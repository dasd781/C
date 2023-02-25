#include<iostream>
using namespace std;

int main()
{
	unsigned char buffer[sizeof(int) * 10];
	//буфер на стеке

	//placement new в буфере
	for (int i = 0; i < 10; ++i)
	{
		int* pInt = new(buffer + sizeof(int) * i)int(i);
	}

	for (int i = 0; i < 10; ++i)
	{
		int* num = (int*)(buffer + sizeof(int) * i);
		cout << *num << endl;
	}
	return 0;
}