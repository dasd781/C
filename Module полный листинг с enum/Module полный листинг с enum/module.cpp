#include "module.h"
#include<iostream>

using namespace std;

namespace study
{
	module::module(moduleType type, const char* name, short tasks, int units, long size)
	{
		moduleName = name;
		tasksCount = tasks;
		unitCount = units;
		moduleSize = size;
		moduleType = type;
	}
	module::module(const char* name, short tasks)
	{
		moduleName = name;
		tasksCount = tasks;
	}
	module::module(const char *name)
	{
		moduleName = name;
	}
	module::module(const module &other)
		
	{
		this->moduleName = other.moduleName;
		this->tasksCount = other.tasksCount;
		this->unitCount = other.unitCount;
		this->moduleSize = other.moduleSize;
	}
	module& module::operator++()
	{
		moduleSize++;
		return *this;
	}
	module& module::operator--()
	{
		moduleSize--;
		return *this;
	}
	module module::operator++(int)
	{
		module old(*this);
		++(*this);
		return old;
	}
	module module::operator--(int)
	{
		module old(*this);
		--(*this);
		return old;
	}
	bool module::operator <(const module& other)
	{
		return this->moduleSize < other.moduleSize;
	}

	bool module::operator >(const module& other)
	{
		return this->moduleSize > other.moduleSize;
	}

	const char* module::getModuleName() const
	{
		return moduleName;
	}

	void module::setModuleName(const char* value)
	{
		moduleName = value;
	}

	short module::getTasksCount() const
	{
		return tasksCount;
	}

	void module::setTasksCount(short value)
	{
		tasksCount = value;
	}

	int module::getUnitCount() const
	{
		return unitCount;
	}

	void module::setUnitCount(int value)
	{
		unitCount = value;
	}

	long module::getModuleSize() const
	{
		return moduleSize;
	}

	void module::setModuleSize(long value)
	{
		if (value > 0)
			moduleSize = value;
		else
			cout << "Нет нет нет, такое значение задать нельзя";
	}

	ostream& operator<<(ostream& output, const module &m) {
		output << "Имя модуля: " << m.moduleName << endl
			<< "Количество задач: " << m.tasksCount << endl
			<< "Количество юнитов: " << m.unitCount << endl
			<< "Размер модуля в страницах: " << m.moduleSize << endl;
		return output;
	}

		

}