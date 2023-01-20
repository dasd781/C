#include<iostream>
using namespace std;

int* findElement(int* arr, int size, int element)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == element)
		{
			return arr + i;//элемент найдем внутри адреса элемента
		}
	}
	return nullptr;// элемент не найден вернуть пустой указатель
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int* element = findElement(arr, 10, 3);
	if (element)
	{
		cout << *element << endl;
	}
	return 0;
}