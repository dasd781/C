#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	while (true)
	{
		char op;
		float num1, num2;
		cout << "Ввкди оператора  - + * / ! ^ али q для выхода из программы" << endl;
		cin >> op;

		if (op == 'q')
		{
			break;
		}
		if (op == '!')
		{
			cout << "Введи число для вычисления факториала :";
			cin >> num1;
		}
		else
		{
			cout << "Введите два числа :" << endl;
			cin >> num1;
			cin >> num2;
		}

		switch (op)// Проверка оператора свичом
		{
		case '+':
			cout << "Результат сложения :" << num1 + num2 << endl;;
			break;

		case '-':
			cout << "Результат вычитания :" << num1 - num2 << endl;;
			break;

		case '*':
			cout << "Результат умножения :" << num1 * num2 << endl;;
			break;

		case '/':
			if (num2 == 0) //проверка не деления на 0
			{
				cout << "Нельзя делить на нуль!!!" << endl;
				break;
			}
			cout << "Результат деления :" << num1 / num2 << endl;
			break;

		case '!':
		{
			int factorial = 1;
			for (int i = 1;i <= num1;++i)
			{
				factorial *= i;
			}
			cout << "Факториал числа :" << num1 << "=" << factorial << endl;

		}
		break;

		case'^':
		{
			float power = 1.0;
			for (int i = 0; i < 0; ++i)
			{
				power *= num1;
			}
			cout << "Результат возведения в степень :" << power << endl;
			break;
		}
		default:
			cin.clear();
			cin.ignore((numeric_limits<std::streamsize>::max(), '\n'));
			cout << "Неправильно указан  оператор" << endl;

		}

	}


	return 0;

}
