﻿
#include <iostream>

int main()
{
    int weekday;

    cout << "Введите число от 1 до 7" << endl;

    cin >> weekday;

    switch (weekday)
    {
    case 1:
        cout << "Понедельник" << endl;
        break;
    case 2:
        cout << "Вторник" << endl;
        break;
    case 3:
        cout << "Среда" << endl;
        break;
    case 4:
        cout << "Четверг" << endl;
        break;
    case 5:
        cout << "Пятница" << endl;
        break;
    case 6:
        cout << "Суббота" << endl;
        break;
    case 7:
        cout << "Воскресенье" << endl;
        break;
    default:
        cout << "Введите число от 1 до 7!" << endl;
        break;
    }

    return 0;
}