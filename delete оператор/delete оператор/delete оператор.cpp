/*int* p_var = new int;
int* p_array = new int[10];

delete p_var;
delete[] p_array;*/
#include<iostream>
using namespace std;
//создаем простой класс
class SomeClass
{
public:
	SomeClass()
	{
		//в конструкторе будем делать вывод в поток вывода
		//что отработал конструктор
		std::cout << "SomeClass::constructor" << std::endl;
	}
	~SomeClass()
	{
		//в деструкторе что отработал деструктор
		std::cout<<"SomeClass::destructor"<<
	}
};