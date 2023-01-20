#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	int arr[] = { 5, 4, 3, 4, 9 };
	int arrayLength = sizeof(arr) / sizeof(arr[0]);
	int evenCount = 0;// Изначальное количество элементов равно 0
	for (int i = 0; i < arrayLength; ++i)
	{
		if (arr[i] % 2 == 0)//Проверяем четность
		{
			++evenCount;
		}
	}
	cout << "Количество четных элементов в массиве {5, 4, 3, 9} равно : " << evenCount << endl;
	return 0;
}
