#include"module.h"//  включение заголовка
#include<iostream>

using namespace std;

void Module::initModule(const char* name, short tasks, int units, long size)
{
	moduleName = name;
	tasksCount = tasks;
	unitsCount = units;
	moduleSize = size;

}
void Module::setName(const char* name)// Изменение имени
{
	moduleName = name;
}
void Module::setSize(long size)
{
	if (size > 0)
		moduleSize = size;
	else
		cout << " Нет нет нет такое значение задать нельзя ";
}
void Module::displayModule()
	{
		cout << " Имя модуля :" << moduleName << endl;
		cout << " Количество задач : " << tasksCount << endl;
		cout << " Количество юнитов :" << unitsCount <<endl;
		cout << "Размер модуля в страницах :" << moduleSize << endl;
	}
		
