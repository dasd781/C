#pragma once
#include <iostream>

using namespace std;

class Module
{
public:
	// ������������
	Module(const char* name, short tasks, int units, long size);
	Module(const char* name, short tasks);
	Module(const char* name);
	Module(const Module& other);
	// ����������
	~Module() = default;
	// ������������� ���������
	Module& operator++(); // ���������� ���-����������
	Module& operator--(); // ���������� ���-����������

	Module operator++(int); // ���������� ����-����������
	Module operator--(int); // ���������� ����-����������

	bool operator < (const Module& other);
	bool operator > (const Module& other);

	// ������� ��� ������ ���������� � �������
	friend ostream& operator<<(ostream& output, const Module& m);

	// ������� � �������
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
