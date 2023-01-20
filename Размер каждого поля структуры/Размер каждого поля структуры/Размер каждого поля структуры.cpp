#include<iostream>
using namespace std;

struct Module
{
	const char* moduleName;//имя модуля
	short tasksCount;//количество задач в модуле
	int unitsCount;//количество юнитов в модуле
	long moduleSize;//   размер модуля в страницах
};
int main()
{
	cout << sizeof(const char*) << "" <<
		sizeof(short) << "" << sizeof(int) << "" <<
		sizeof(long) << endl;

	//То есть размер const char* — 8 байт (для 64-х разрядной операционной системы, 4 — для 32-х разрядной), размер short — 
	//2 байта и так далее. Но при выводе размера структуры целиком:

	return 0;
 }