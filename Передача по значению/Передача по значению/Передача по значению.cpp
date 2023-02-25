#include<iostream>

//Эта функция имеет два параметра int : a и b/
//Значение переменных определяет caller
void printValues(int a, int b)
{
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}
int add(int a, int b)
{
	return a + b;
}
int main()
{
	printValues(8, 9);// здесь два аргумента : 8 и 9
	std::cout << add(7, 8) << std::endl;//аргументы 7 и 8 передаются в функцию

	return 0;
}