#include"Module.h"
#include<iostream>
using namespace std;

int main()
{
	Module m1("Functions", 10, 5, 15);
	Module m2("Functions", 10, 5, 20);
	if (m1 < m2)
	{
		cout << "Первый больше второго " << endl;
	}
	if (m1 > m2)
	{
		cout << "Первый меньше второго " << endl;
	}
	return 0;
}