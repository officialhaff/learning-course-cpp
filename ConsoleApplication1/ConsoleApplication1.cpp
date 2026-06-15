// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cstdlib>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#endif

using namespace std::chrono_literals;

// ---------- Кроссплатформенные функции для неблокирующего ввода ----------
bool is_key_pressed() {
#ifdef _WIN32
    return _kbhit() != 0;
#else
    struct timeval tv = { 0, 0 };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &tv) > 0;
#endif
}

void clear_key_buffer() {
#ifdef _WIN32
    while (_kbhit()) _getch();
#else
    // В POSIX достаточно прочитать всё, что есть в буфере
    char ch;
    while (read(STDIN_FILENO, &ch, 1) > 0) {}
#endif
}

// RAII-обёртка для переключения терминала в неканонический режим (POSIX)
#ifndef _WIN32
class NonCanonicalTerminal {
    struct termios old_settings;
    bool valid;
public:
    NonCanonicalTerminal() : valid(false) {
        if (tcgetattr(STDIN_FILENO, &old_settings) == 0) {
            struct termios new_settings = old_settings;
            new_settings.c_lflag &= ~(ICANON | ECHO);
            new_settings.c_cc[VMIN] = 0;
            new_settings.c_cc[VTIME] = 0;
            tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
            valid = true;
        }
    }
    ~NonCanonicalTerminal() {
        if (valid) {
            tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
        }
    }
};
#endif
// -------------------------------------------------------------------------

// Форматирует оставшееся время в строку "MM:SS"
std::string format_time(int total_seconds) {
    int mins = total_seconds / 60;
    int secs = total_seconds % 60;
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << mins << ':'
        << std::setw(2) << std::setfill('0') << secs;
    return oss.str();
}

int main() {
    // Надёжный ввод минут
    std::setlocale(0, "");
    int afk_minutes = 0;
    while (true) {
        std::cout << "Введите время отсутствия (минуты): ";
        std::cin >> afk_minutes;
        if (std::cin.fail() || afk_minutes < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите целое неотрицательное число.\n";
        }
        else {
            break;
        }
    }

    if (afk_minutes == 0) {
        std::cout << "Время не задано, программа завершена.\n";
        return 0;
    }

    auto total_seconds = std::chrono::seconds(afk_minutes * 60);
    auto end_time = std::chrono::steady_clock::now() + total_seconds;

    // Установка неканонического режима на POSIX
#ifndef _WIN32
    NonCanonicalTerminal nc_term;
#endif

    std::cout << "" << std::endl;
    std::cout << "Пользователь отошел от компьютера.\n" << std::endl;
    std::cout << "Таймер запущен. Нажмите любую клавишу для досрочной остановки.\n";

    bool interrupted = false;
    auto last_display_update = std::chrono::steady_clock::now();

    // Основной цикл с проверкой клавиши
    while (true) {
        auto now = std::chrono::steady_clock::now();
        if (now >= end_time) {
            break;  // таймер истёк
        }

        // Проверяем нажатие клавиши
        if (is_key_pressed()) {
            interrupted = true;
            clear_key_buffer(); // убираем символ, чтобы не повлиял на последующий ввод
            break;
        }

        // Обновляем отображение раз в секунду (не чаще)
        if (now - last_display_update >= 1s) {
            auto remaining = std::chrono::duration_cast<std::chrono::seconds>(end_time - now).count();
            std::string display = "Осталось: " + format_time(static_cast<int>(remaining));
            std::cout << '\r' << std::left << std::setw(30) << std::setfill(' ') << display << std::flush;
            last_display_update = now;
        }

        // Спим небольшой интервал для снижения нагрузки на CPU (100 мс)
        auto next_check = now + 100ms;
        if (next_check > end_time) next_check = end_time;
        std::this_thread::sleep_until(next_check);
    }

    // Финальный вывод
    auto now = std::chrono::steady_clock::now();
    if (interrupted) {
        auto remaining = std::chrono::duration_cast<std::chrono::seconds>(end_time - now).count();
        if (remaining < 0) remaining = 0;
        std::cout << "\rТаймер остановлен досрочно. Оставалось: "
            << format_time(static_cast<int>(remaining)) << "     \n";
    }
    else {
        std::cout << "\rПользователь скоро подойдет!      \n";
    }

    std::cout << "Нажмите Enter для выхода..." << std::flush;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
