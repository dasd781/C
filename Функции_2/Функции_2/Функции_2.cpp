#include<iostream>
using namespace std;

int Add(int a, int b)
{
	int sum = a + b;
	return sum;
}
int main(int argc, char* argv[])
{
	int a = 4;
	int b = 8;

	int sum = Add(a, b);
	cout << sum << endl;
	return 0;
}
