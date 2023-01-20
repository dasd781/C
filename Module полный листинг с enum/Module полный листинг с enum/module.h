#pragma once
#include<iostream>

using namespace std;

namespace study
{
	enum moduleType
	{
		FUNCTION = 0,
		OOP,// ����� ����� �������
		CLASSES//����� ����� ������
	};

	class module
	{
	public:
		//������������
		module(moduleType type, const char* name, short tasks, int units, long size);
		module(const char* name, short tasks);
		module(const char* name);
		module(const module& other);
		// �����������
		~module() = default;
		//������������� ���������
		module& operator++();//���������� ���-����������
		module& operator--();//���������� ��� - ����������
		module operator++(int);//���������� ���� - ����������
		module operator--(int);//���������� ��� - ����������

		bool operator < (const module& other);
		bool operator > (const module& other);

		//������� ��� ������ ���������� � �������
		friend ostream& operator << (ostream& output, const module& m);

		//������ � ������
		const char* getModuleName() const;
		void setModuleName(const char* value);

		short getTasksCount() const;
		void setTasksCount(short value);

		int getUnitCount() const;
		void setUnitCount(long value);

		long getModuleSize() const;
		void setModuleSize(long value);

	private:
		const char* moduleName;
		short tasksCount;
		int unitCount;
		long moduleSize;
		moduleType moduleType;


	};
}
