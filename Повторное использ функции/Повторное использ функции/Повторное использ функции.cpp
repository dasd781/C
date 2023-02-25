#include<iostream>
using namespace std;

int GetValue()
{
	std::cout << "Enter an integer : " ;
	int x;
	std::cin >> x;
	return x;
}
void printO()
{
	std::cout << "O";
}
void printK()
{
	std::cout << "K" << std::endl;
}

void printOK()
{
	printO();
	printK();
}

int main()
{
	printOK();

	int a = GetValue();
	int b = GetValue();

	std::cout << a << '+' << b << '=' << a + b << std::endl;

	return 0;
}