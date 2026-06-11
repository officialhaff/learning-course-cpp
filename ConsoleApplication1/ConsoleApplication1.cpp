// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;



int main()
{
	setlocale(0, "");
	int TaskNumber;

	cout << "Введите номер задачи: ";
	cin >> TaskNumber;

	if (TaskNumber >= 11 || TaskNumber <= 0)
	{
		cout << "Ошибка";

		return 0;
	}

	if (TaskNumber == 1)
	{
		int x;
		cout << "Введите число: ";
		cin >> x;

		if (x > 0)
		{
			cout << "POSITIVE" << endl;
		}
		else if (x < 0)
		{
			cout << "NEGATIVE" << endl;
		}
		else if (x == 0)
		{
			cout << "ZERO" << endl;
		}
	}

	if (TaskNumber == 2)
	{
		int x;
		cout << "Введите число: ";
		cin >> x;

		if (x >= 18 && x <= 110)
		{
			cout << "Adult" << endl;
		}
		else if (x < 18 && x > 0)
		{
			cout << "Minor" << endl;
		}
		else
		{
			cout << "В планах родить";
		}
	}

	if (TaskNumber == 3)
	{
		int x;
		cout << "Введите число: ";
		cin >> x;

		if (x > 0 && x < 100)
		{
			cout << "KRASAVCHIK" << endl;
		}
		else
		{
			cout << "IDI NAHYU" << endl;
		}
	}

	if (TaskNumber == 4)
	{
		int x;
		cout << "Введите число: ";
		cin >> x;

		if (x % 3 == 0 && x % 5 == 0)
		{
			cout << "Число: " << x << " делится на 3 и на 5" << endl;
		}
		else
		{
			cout << "IDI NAHYU" << endl;
		}
	}

	if (TaskNumber == 5)
	{
		int x, y;
		cout << "Введите первое число: ";
		cin >> x;
		cout << "Введите второе число: ";
		cin >> y;

		int max = (x > y ? x : y);

		cout << "Наибольшее из чисел: " << max << endl;
	}

	if (TaskNumber == 6)
	{
		int x = 5;
		int y = 2;
		double MaxCount = (double)x / (double)y;

		cout << MaxCount << endl;
	}

	if (TaskNumber == 7)
	{
		int x;
		cout << "Введите число: ";
		cin >> x;

		switch (x)
		{
		case 1:
			cout << "Понедельник";
			break;
		case 2:
			cout << "Вторник";
			break;
		case 3:
			cout << "Среда";
			break;
		case 4:
			cout << "Четверг";
			break;
		case 5:
			cout << "Пятница";
			break;
		case 6:
			cout << "Суббота";
			break;
		case 7:
			cout << "Воскресенье";
			break;
		default:
			cout << "Ошибка";
			break;
		}
	}

	if (TaskNumber == 8)
	{
		int x;
		cout << "Введите число: ";
		cin >> x;

		if (x == 1)
		{
			cout << "Играть" << endl;
		}
		else if (x == 2)
		{
			cout << "Настройки" << endl;
		}
		else if (x == 3)
		{
			cout << "Выход" << endl;
		}
		else
		{
			cout << "Ошибка" << endl;
		}

	}
	
	if (TaskNumber == 9)
	{
		int x;
		cout << "Введите число: ";
		cin >> x;

		switch (x)
		{
		case 1:
			cout << "Январь";
			break;
		case 2:
			cout << "Февраль";
			break;
		case 3:
			cout << "Март";
			break;
		case 4:
			cout << "Апрель";
			break;
		case 5:
			cout << "Май";
			break;
		case 6:
			cout << "Июнь";
			break;
		case 7:
			cout << "Июль";
			break;
		case 8:
			cout << "Август";
			break;
		case 9:
			cout << "Сентябрь";
			break;
		case 10:
			cout << "Октябрь";
			break;
		case 11:
			cout << "Ноябрь";
			break;
		case 12:
			cout << "Декабрь";
			break;
		default:
			cout << "Ошибка";
			break;
		}
	}

	if (TaskNumber == 10)
	{
		int x;
		cout << "Введите число: ";
		cin >> x;

		if (x == 1)
		{
			cout << "+" << endl;
		}
		else if (x == 2)
		{
			cout << "-" << endl;
		}
		else if (x == 3)
		{
			cout << "*" << endl;
		}
		else if (x == 4)
		{
			cout << "/" << endl;
		}
		else
		{
			cout << "Ошибка" << endl;
		}

	}

	cin.ignore(); // Очищаем буфер от лишних символов

	cout << "Нажмите Enter для выхода...";

	cin.get(); // Ждем нажатия клавиши Enter

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
