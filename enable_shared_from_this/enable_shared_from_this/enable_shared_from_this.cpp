#include<iostream>
#include<memory>
using namespace std;

class Int : public enable_shared_from_this<Int> //указываем класс Int как параметр
	// шаблона  enable_shared_from_this
{
public:
	Int(int i = 0) : _int(i)
	{
		cout << "constructor" << _int << endl;
	}
	~Int()
	{
		cout << "destructor : " _int << endl;
	}
	void SetInt(int i)
	{
		_int = i;
		cout << "Int set to : " _int << endl;
	}
	int GetInt()
	{
		return _int;
	}
	shared_ptr<Int> GetPtr()
	{
		return shared_from_this();//метод который возвращает shared_ptr
	}
private:
	int _int;
};