/*эта функцияя не имеет параметров
void doPrint()
{
	std::cout << "in doPrint()" << std::endl;
}
//Эта функция имеет один параметр  int
void printValue(int a)
{
	std::cout << a << std::endl;
}
//эта функция имеет два параметра
int add(int a, int b)
{
	return a + b;
}*/

#include<iostream>
//эта функция имеет два параметра типа  int a, b.
// значания a , b определены в калер
void printValues(int a, int b)
{
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}
int main()
{
	printValues(8, 9);//здесь два аргумента 8 и 9

		return 0;
}