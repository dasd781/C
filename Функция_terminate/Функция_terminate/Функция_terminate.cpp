#include<iostream>
using namespace std;

void Foo()
{
	throw "Exception";
}
void MyQuit()
{
	cout << " Terminating due to uncaught exeception" << endl;
	exit(5);
}
int main()
{
	set_terminate(MyQuit);
	Foo();
	return 0;
}