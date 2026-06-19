//
// Created by houp on 19.06.2026.
//

#include <iostream>
using namespace std;

int main() {

    cout << "------------------------------" << endl;
    cout << "SmartCalculator-version 1.0" << endl;

    int firstNumber, secondNumber;
    cout << "Введите первое число: ";
    cin >> firstNumber;
    cout << "Введите второе число: ";
    cin >> secondNumber;

    cout << "---Блок арифметических операций---" << endl;

    cout << "Результат сложения: " << firstNumber + secondNumber << endl;
    cout << "Результат вычитания: " << firstNumber - secondNumber << endl;
    cout << "Результат умножения: " << firstNumber * secondNumber << endl;
    cout << "Результат деления: " << static_cast<double>(firstNumber) / static_cast<double>(secondNumber) << endl;

    cout << "---Блок логических операций---" << endl;

    if (firstNumber > secondNumber)
    {
        cout << "Число " << firstNumber << " больше, чем число " << secondNumber << endl;
    }
    else if (firstNumber < secondNumber)
    {
        cout << "Число " << secondNumber << " больше, чем число " << firstNumber << endl;
    }
    else
    {
        cout << "Число " << firstNumber << " равно числу " << secondNumber << endl;
    }

    cout << "------------------------------" << endl;

    if (firstNumber == secondNumber)
    {
        cout << "Числа " << firstNumber << " и " << secondNumber << " равны между собой" << endl;
    }
    else
    {
        cout << "Числа " << firstNumber << " и " << secondNumber << " не равны между собой" << endl;
    }

    cout << "------------------------------" << endl;

    if (firstNumber != 0 && secondNumber != 0 && firstNumber % secondNumber == 0 && secondNumber % firstNumber == 0)
    {
        cout << "Числа " << firstNumber << " и " << secondNumber << " делятся друг на друга" << endl;
    }
    else
    {
        cout << "Числа " << firstNumber << " и " << secondNumber << " не делятся друг на друга" << endl;
    }

    cout << "------------------------------" << endl;

    cin.ignore();
    cout << "Нажмите Enter для продолжения..." << endl;
    cin.get();
}