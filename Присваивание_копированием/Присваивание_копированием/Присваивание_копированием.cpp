#include<iostream>
using namespace std;

class Int
{
public:
	int* pi;
	Int()
	{
		pi = new int(1);
	}
	Int(const Int& other)
	{
		pi = new int(*other.pi);//выделяем память под свой экземпляр переменной и копируем
		//туда значение которое содержит в переменной other
	}
	Int& operator = (const Int& other)
	{
		pi = new int(*other.pi);//выделяем память под свой экземпляр переменной и копируем
		//туда значение которое содержится в переменной other
	}
	~Int()
	{
		delete pi;
	}
};
int main()
{
	{
		Int i;
		Int j = i;
	}
	return 0;
}