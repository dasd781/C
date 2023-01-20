#include<iostream>
using namespace std;

int main()
{
	int array[7] = { 2,3,4,5,2,8,10 };
	for (int i = 0; i < 7; ++i)
	{
		cout << array[i] << " ";// вывод каждого элемента через пробел
	}
	return 0;
}