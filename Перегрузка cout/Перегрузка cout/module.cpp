#include "module.h"
ostream &operator << (ostream& output, const Module &m)
{
	output << "  Имя модуля " << m.moduleName << endl
		<< "Количество задач :" << m.tasksCount << endl
		<< "Количество юнитов:" << m.unitsCount << endl
		<< "Размер модуля в страницах : " << endl;
	return output;

}