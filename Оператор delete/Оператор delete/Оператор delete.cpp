#include<iostream>
using namespace std;

/*int* p_var = new int;
int* p_array = new int[10];

delete p_var;
delete[] p_array; */

class SomeClass
{
public:
	SomeClass()
	{
		//В конструкторе будем делать вывод в поток ввода
		//что отработал конструктор
		std::cout << "SomeClass::constructor" << std::endl;
	}
	~SomeClass()
	{
		//в деструкторе что отработтал деструктор
		std::cout << "SomeClass::destructor" << std::endl;
	}

};
int main(int argc,char *argcv[])

{
	SomeClass* obj = new SomeClass();//локальный обьект 
	//создается на стэке
	delete obj;//и уничтожается в конце области видимости
}