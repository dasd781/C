#include<iostream>

	//Получить первое значение от пользователя
	int getUserInput()
	{
		std::cout << "Pleas enter an integer : ";
		int value;
		std::cin >> value;
		return value;
	}

	//Получить математическую операцию от пользовател
	int getMathematicalOperation()
	{
		std::cout << "Please enter which operator you want ( 1 = +, 2 = -, 3 = *,4 = / ) : ";
		int op;
		std::cin >> op;
		//а что если пользователь введет некорректный символ?
		//Пока что это мы проигнорируем
		return op;
	}

	//Вычислить результат
	int calculaterResult (int x, int op, int y)
	{
		//щбратите внимание щператор == используется для сравнерия двух значений
		if (op == 1)//усли пользователь выбрал операцию сложения (1)
			return x + y; // то выполняем эту строку
		if (op == 2)// если пользователь выбрал вычисление операцию (2)
			return x - y;// то выполняем эту строку
		if (op == 3)//если пользователь выбрал операцию умножения(3)
			return x * y;// то выполняем эту строку
		if (op == 4)// если поьльзователь выбрал операцию деления (4)
			return x / y;// nj dsgjkyz.n 'ne cnhjre

		return -1; // вариант если пользователь ввел не корректно символ
	}

	//вывести результат
	void printResult(int result)
	{
		std::cout << "Your result is : " << result << std::endl;
	}

	int main()
	{
		//Получаем первое значение от пользователя
		int input1 = getUserInput();
		//получаем математическую операцию от пользователя
		int op = getMathematicalOperation();
		// поллучаем второе значение от пользователя
		int input2 = getUserInput();
		//вычесляем результат и сохраняем его во временной переменной
		int result = calculaterResult(input1, op, input2);
		// Выводим результат
		printResult(result);
	}
