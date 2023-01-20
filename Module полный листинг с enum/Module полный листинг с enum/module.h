#pragma once
#include<iostream>

using namespace std;

namespace study
{
	enum moduleType
	{
		FUNCTION = 0,
		OOP,// будет равен единице
		CLASSES//будет равен двойке
	};

	class module
	{
	public:
		//Конструкторы
		module(moduleType type, const char* name, short tasks, int units, long size);
		module(const char* name, short tasks);
		module(const char* name);
		module(const module& other);
		// деструкторы
		~module() = default;
		//перегруженные операторы
		module& operator++();//перегрузка пре-инкремента
		module& operator--();//перегрузка пре - декремента
		module operator++(int);//перегрузка посе - инкремента
		module operator--(int);//перегрузка пос - декремента

		bool operator < (const module& other);
		bool operator > (const module& other);

		//функция для вывода информации в консоль
		friend ostream& operator << (ostream& output, const module& m);

		//гетеры и сетеры
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
