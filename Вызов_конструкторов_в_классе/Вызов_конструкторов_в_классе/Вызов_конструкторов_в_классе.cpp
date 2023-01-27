#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base class constructed" << endl;
	}
	virtual ~Base()
	{
		cout << "Base class destructed" << endl;
	}
};
class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived class constructed " << endl;
	}
	~Derived()
	{
		cout << "Derived class destructed" << endl;
	}
};
class MoreDerived : public Derived
{
public:
	MoreDerived()
	{
		cout << "MoreDerived class constructed" << endl;
	}
	~MoreDerived()
	{
		cout << "MoreDerived class destructed" << endl;
	}
};
int main()
{
	MoreDerived moreDerived;
	return 0;
}
