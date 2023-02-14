#include<iostream>
#include<string>

using namespace std;

struct A
{
	int a;
	union {
		int b;
		double c;
	};
};

union Container
{
	int int_fieled;
	double double_fieled;
};

int main()
{
	Container container;
	container.double_fieled = 0.5;

	A a;
	a.b = 2;
	A* a_ptr;
	Container* cnt_ptr;

	a_ptr->a;

	cout << a.b << "\n";
	cout << a.c << "\n";
	cout << sizeof(A) << "\n";

	cout << sizeof(container) << "\n";

	cout << container.int_fieled << "\n";
	cout << container.double_fieled << "\n";
	container = { 4 };

	cout << container.int_fieled << "\n";
	cout << container.double_fieled << "\n";
	return 0;
}