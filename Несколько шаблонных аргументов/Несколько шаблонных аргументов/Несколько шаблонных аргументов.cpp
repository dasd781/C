#include<iostream>
using namespace std;

//Шаблонная функция
template <typename T1, typename T2 >void show(T1 x, T2 y, string str)
{
	cout << str << x << endl;
	cout << str << y << endl;
}

int main()
{
	setlocale(LC_ALL, "");

	// вызов шаблона функции
	show<int, double>(1, 2.5, "Argument = ");
	show<string, char>("Text", 'H', "ArgumentA = ");

	return 0;
}