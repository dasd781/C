


/*try
{
	int code = ReadCodeFile(faile, key);
}
catch (char* exception)
{
	cout << "Error reading code" << endl;
}

int RedCodeFromFile(File* f, std::string key)
{
	assert(f);
	try
	{
		return f.RedCode(key);//генерирует исключение типа int если не удалось
		//найти код по ключу
	}
	catch (int exception)
	{
		//запись ошибки в глобальный журнал ошибок
		g_log.logerror("failed read code from faile");

		throw exception;// генерируем тоже исключение снова
	}
}*/
#include<iostream>
using namespace std;
class Base
{
public:
	Base()
	{
	}
	virtual void Show()
	{
		cout << "Base Exception " << endl;
	}
};
class Derived : public Base
{
public:
	Derived()
	{
	}
	virtual void Show()
		override
	{
		cout << "Derived Exception " << endl;
	}
};
int main()
{
	try
	{
		try
		{
			throw Derived();//  генерация исключения класса наследника  Derived
		}
		catch (Base& b)
		{
			cout <<""
		}
	}
}