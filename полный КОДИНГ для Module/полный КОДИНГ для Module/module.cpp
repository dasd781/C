#pragma once
#include <iostream>

using namespace std;

class Module
{
public:
	// Конструкторы
	Module(const char* name, short tasks, int units, long size);
	Module(const char* name, short tasks);
	Module(const char* name);
	Module(const Module& other);
	// Деструктор
	~Module() = default;
	// Перегруженные операторы
	Module& operator++(); // Перегрузка пре-инкремента
	Module& operator--(); // Перегрузка пре-декремента

	Module operator++(int); // Перегрузка пост-инкремента
	Module operator--(int); // Перегрузка пост-декремента

	bool operator < (const Module& other);
	bool operator > (const Module& other);

	// Функция для вывода информации в консоль
	friend ostream& operator<<(ostream& output, const Module& m);

	// Геттеры и сеттеры
	const char* getModuleName() const;
	void setModuleName(const char* value);

	short getTasksCount() const;
	void setTasksCount(short value);

	int getUnitsCount() const;
	void setUnitsCount(int value);

	long getModuleSize() const;
	void setModuleSize(long value);

private:
	const char* moduleName;
	short tasksCount;
	int   unitsCount;
	long  moduleSize;
};
