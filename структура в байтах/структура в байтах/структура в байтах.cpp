#include<iostream>
using namespace std;

int main()
{
	struct SomeData
	{
		int a;
		unsigned int b;
		double c;
		char reserved[16];
	};
	cout << sizeof SomeData << endl;
	return 0;
}