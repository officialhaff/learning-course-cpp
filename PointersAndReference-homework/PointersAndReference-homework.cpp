//
// Created by houp on 20.06.2026.
//

#include <iostream>
using namespace std;


int main() {

    setlocale(0, "");

    int pointerTask;

    cout << "Введите номер задачи: ";
    cin >> pointerTask;

    if (pointerTask >= 9 || pointerTask <= 0)
    {
        cout << "Ошибка";

        return 0;
    }

    if (pointerTask == 1) {

        int age { 20 };
        double height { 1.75 };
        char letter { 'A' };

        cout << "---------------------------------" << endl;
        cout << "Значение переменной age равно: " << age << endl;
        cout << "Адрес в памяти для хранения переменной age: " << &age << endl;

        cout << "---------------------------------" << endl;
        cout << "Значение переменной height равно: " << height << endl;
        cout << "Адрес в памяти для хранения переменной height: " << &height << endl;

        cout << "---------------------------------" << endl;
        cout << "Значение переменной letter равно: " << letter << endl;

        /*
         void* - это указатель на неопределённый тип, или «универсальный указатель».
         Он может хранить адрес любого объекта (любого типа),
         потому что любой указатель на объект неявно преобразуется в void*

        Потоковый оператор << в std::cout имеет несколько перегрузок для разных типов указателей:
        std::ostream& operator<<(std::ostream&, const char*);
        Интерпретирует указатель как C‑строку и выводит символы до встречи нуль‑терминатора '\0'.

        void* не может быть спутан со строкой, поэтому поток просто печатает числовой адрес
        (обычно в формате 0x7ffe...).

        void* уникален и применяется только к типу данных char.
         */

        cout << "Адрес в памяти для хранения переменной letter: " << static_cast<void*>(&letter) << endl;
        cout << "---------------------------------" << endl;

    }

    if (pointerTask == 2) {

        int number { 100 };

        int& ref = number;

        ref = 101;

        cout << "Значение переменной ref: " << ref << endl;
        cout << "Значение переменной number: " << number << endl;

    }

    if (pointerTask == 3) {

        int x = 50;

        const int& ref = x;

        x = 51;

        cout << ref << endl;
        cout << x << endl;

    }

    if (pointerTask == 4) {

        const int& value = 7 * 8;

        cout << value << endl;

    }

    if (pointerTask == 5) {

        int x = 25;

        int* ptr = &x;

        cout << ptr << endl;
        cout << *ptr << endl;

        x = 100;

        *ptr = 101;

        cout << x << endl;

    }

    if (pointerTask == 6) {

        int* ptr = nullptr;

        if (ptr == nullptr) {

            cout << "Pointer is null" << endl;

        }

    }

    if (pointerTask == 7) {

        int* ptr = new int;

        *ptr = 50;

        cout << *ptr << endl;

        delete ptr;

    }

    if (pointerTask == 8) {

        int* arr = new int[3];

        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;

        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

        delete[] arr;

    }


    cin.ignore();
    cout << "Нажмите Enter для продолжения..." << endl;
    cin.get();

}