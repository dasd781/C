/*#include<iostream>
using namespace std;

void func2()
{
	cout << "func2() call " << endl;
	throw "func2 exception thrown ! ";
	cout << "func2() end  " << endl;
}
void func()
{
	cout << "func() call" << endl;
	func2();
	cout << "func() end " << endl;
}
int main()
{
	cout << "main start " << endl;
	try
	{
		func();
	}
	catch (const char* exception)
	{
		cout << "Exception : " << exception << endl;
	}
	cout << "main end " << endl;
	return 0;
}*/

#include <iostream>
using namespace std;
class A
{
};
class B
{
};
class C
{
};
class D
{
};

void Foo()
{
	A a;
	throw "exception";
}

void Bar()
{
	B b;
	Foo();
}

void Fuzz()
{
	D d;
	Bar();
}

int main()
{
	C c;
	try
	{
		Fuzz();
	}
	catch (const char* e)
	{
		cout << e << endl;
	}

	return 0;
}