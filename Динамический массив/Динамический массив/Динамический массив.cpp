#include<iostream>
using namespace std;

int main()
//пример работы с статическим массивом
{
	const int size = 10;
	int staticArray[size];
	for (int i = 0; i < size; ++i)
	{
		staticArray[i] = i;
	}
	for (int i = 0; i < size; ++i)
	{
		cout << staticArray[i] << endl;
	}
	//пример работы с динамическим массивом
	int* dynamicArray = new int[size];
	for (int i = 0; i < size; ++i)
	{
		dynamicArray[i] = i;
	}
	for (int i = 0; i < size; ++i)
	{
		cout << dynamicArray[i] << endl;
	}
	delete[] dynamicArray; //не забыаем удалить 

	return 0;
}