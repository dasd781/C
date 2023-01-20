#include<iostream>
#include<functional>

int add(int, int);
int subtract(int, int);
int multiply(int, int);
std::function<int(int, int)>select();

int main()
{
	int x = 8;
	int y = 5;
	std::cout << "x = " << x << "\ty = " << y << std::endl;
	std::cout << "1 : Add " << std::endl;
	std::cout << "2 : Subtract " << std::endl;
	std::cout << " 3 : Multiply " << std::endl;
	std::cout << "4 : Exit " << std::endl;

	while (true)
	{
		auto action = select();//получаем указатель на функцию
		if (action == nullptr)
			break;
		std::cout << "Result :" << action(x, y) << std::endl;
	}
	std::cout << "The Endl" << std::endl;

	return 0;
}

std::function<int(int, int)>select()
{
	int choice; //выбранный пункт
	//  массив указателей на функции которые будут возвращатся
	int(*actions[])(int x, int y) = { add, subtract, multiply };
	// выбираем действие по номеру
	std::cout << "Enter action(1, 2, 3, 4) :";
	std::cin >> choice;
	//  возвращаем нужную функцию
	if (choice > 0 && choice < 4)
		return actions[choice - 1];
		return nullptr;
}
int add(int x, int y)
{
	return x + y;
}
int subtract(int x, int y)
{
	return x - y;
}
int multiply(int x, int y)
{
	return x * y;
}

//дописать конец программы