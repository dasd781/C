#include"module.h"//  ��������� ���������
#include<iostream>

using namespace std;

void Module::initModule(const char* name, short tasks, int units, long size)
{
	moduleName = name;
	tasksCount = tasks;
	unitsCount = units;
	moduleSize = size;

}
void Module::setName(const char* name)// ��������� �����
{
	moduleName = name;
}
void Module::setSize(long size)
{
	if (size > 0)
		moduleSize = size;
	else
		cout << " ��� ��� ��� ����� �������� ������ ������ ";
}
void Module::displayModule()
	{
		cout << " ��� ������ :" << moduleName << endl;
		cout << " ���������� ����� : " << tasksCount << endl;
		cout << " ���������� ������ :" << unitsCount <<endl;
		cout << "������ ������ � ��������� :" << moduleSize << endl;
	}
		
