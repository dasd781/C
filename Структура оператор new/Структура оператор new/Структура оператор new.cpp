#include<iostream>
using namespace std;

struct Module
{
	const char* moduleName;//Имя модуля
	short tasksCount;//Количество задач в модуле
	int unitsCount;// Количество юнитов в модуле
	long moduleSize;
};
int main()
{
	Module* m = new Module;
	//Код программы
	m -> moduleName = "Функции";
	m -> moduleSize = 15;
	m -> tasksCount = 5;
	m -> moduleSize = 10;
	delete m;
	return 0;
}