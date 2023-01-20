#include <iostream>
using namespace std;

int Add(int a, int b)
{
    return a + b;
}

int Substitute(int a, int b)
{
    return a - b;
}

int Divide(int a, int b)
{
    return a / b;
}

int Multiply(int a, int b)
{
    return a * b;
}

int Factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * Factorial(n - 1);
}

int Power(int base, int power)
{
    if (power != 0)
        return (base * Power(base, power - 1));
    else
        return 1;
}

int main()
{
    setlocale(LC_ALL, "");

    while (true)
    {
        char op;
        int  num1, num2;
        cout << "Введите оператор + - * / ! ^ " << endl;
        cin >> op;

        if (op == 'q')
        {
            break; // или return 0;
        }

        if (op == '!')
        {
            cout << "Введите число для вычисления факториала:";
            cin >> num1;
        }
        else
        {
            cout << "Введите два числа" << endl;
            cin >> num1;
            cin >> num2;
        }


        switch (op)
        {
        case '+':
            cout << "Результат сложения: " << Add(num1, num2) << endl;
            break;

        case '-':
            cout << "Результат вычитания: " << Substitute(num1, num2) << endl;
            break;

        case '*':
            cout << "Результат умножения: " << Multiply(num1, num2) << endl;
            break;

        case '/':
            if (num2 == 0)
            {
                cout << "нельзя делить на ноль!" << endl;
                break;
            }

            cout << "Результат деления: " << Divide(num1, num2) << endl;
            break;

        case '!':
        {
            int factorial = Factorial(num1);
            cout << "Факториал числа: " << num1 << " = " << factorial << endl;
        }
        break;

        case '^':
        {
            float power = Power(num1, num2);
            cout << "Результат возведения в степень: " << power << endl;
            break;
        }


        default:
            cout << "Неправильно указан оператор" << endl;
            break;
        }
    }


    return 0;
}