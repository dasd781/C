#include "module.h"
ostream &operator << (ostream& output, const Module &m)
{
	output << "  ��� ������ " << m.moduleName << endl
		<< "���������� ����� :" << m.tasksCount << endl
		<< "���������� ������:" << m.unitsCount << endl
		<< "������ ������ � ��������� : " << endl;
	return output;

}