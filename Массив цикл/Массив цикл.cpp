#include<iostream>
using namespace std;

int main()
{
	int const size = 10;
	int array[size];

	for (int i = 0; i < 10; ++i)
	{
		cin >> array[i];
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << array[i];
	  }

	int i = 0;// пример цикла while примененгие с массивом
	while (i < 10)
	{
		cin >> array[i];
		i++;
	}
	i = 0;
	while (i < 10)
	{
		cout << array[i];
		i++
	}

	return 0;
}