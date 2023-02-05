/*#include<iostream>
#include<cstdlib>

using namespace std;

class Foo
{
public:
	Foo() { cout << "Foo object constructed" << endl; }
	~Foo() { cout << "Foo objct destructed " << endl; }
};
int Divide(int a, int b)
{
	if (b == 0)
	{
		abort();
	}
	int result = a / b;
	return result;
}
int main()
{
	Foo f;
	int a = 4;
	int b = 0;

	int c = Divide(a, b);
	cout << "Division result : " << c << endl;

	return 0;
}*/
#include<iostream>
#include<assert.h>
using namespace std;

int Divide(int a, int b)
{
	assert(b);
	int result = a / b;
	return result;
}
int main()
{
	int a = 4;
	int b = 0;

	int c = Divide(a, b);
	cout << "Division result : " << c << endl;
	return 0;
}