#include<iostream>t
using namespace std;

struct Module
{
	const char *moduleName;// Имя модуля
	short taskCount;// Количество задач в модуле
	int unitsCount;// Количество юнитов в модуле
	long moduleSize;// Рфзмер модуля в страницах

};
void initModule(Module& module, const char* name,
	short tasks, int units, long size)//Функция иницилизации 

{
	module.moduleName = name;
	module.taskCount = tasks;
	module.unitsCount = units;
	module.moduleSize = size;
}
void setName(Module& module, const char* name)// Изменение имени
{
	module.moduleName = name;
}
void setSize(Module& vodule, long size)//Изменение обьема модуля
{
	module.moduleSize = size;
}
void displayModule(Module m)
{
	cout << "Имя модуля :" << m.moduleName << endl;
	cout << "Количество задач :" << m.taskCount << endl;
	cout << "Количество юнитов :" << m.unitsCount << endl;
	cout << "Размер модуля в страницах :" << m.moduleSize << endl;


}