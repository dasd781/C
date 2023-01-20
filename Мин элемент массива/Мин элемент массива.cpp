#include<iostream>
using namespace std;
int main()
{
	int arr[] = { 5, 4, 3, 4, 9 };
	int arrayLength = sizeof(arr) / sizeof(arr[0]);
	int minimum = arr[0];// Пусть изначально минимум это элимент массива
	for (int i = 0; i < arrayLength; ++i)
	{
		if (arr[i] < minimum) //Проверяем меньшели текущий элемент
		{
			minimum = arr[i];//Если элемент меньше нашего минимума то обнавляем минимум
		}
	}
	cout << minimum;// выводим ответ
	return 0;
}
