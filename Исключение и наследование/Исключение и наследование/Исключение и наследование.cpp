#include<iostream>
using namespace std;

 /*class Base
{
public:
	Base()
	{
	}
};
class Derived : public Base
{
public:
	Derived()
	{
	}
};
int main()
{
	try
	{
		throw Derived();
	}
	catch (const Base& base)
	{
		cout << "exception : caught Base class" << endl;
	}
	catch (const Derived& derived)
	{
		cout << "Exception : caught Derived class" << endl;
	}
	return 0;
}*/
class Base {};
class Derived : public Base {};
int main()
{
	Derived d;
	try
	{
		throw d;
	}
	catch (Base& b)
	{
		cout << "Caught Base Exception";
	}
	catch (Derived& d)
	{
		cout << "Caught Derived Exception";
	}
	return 0;
}