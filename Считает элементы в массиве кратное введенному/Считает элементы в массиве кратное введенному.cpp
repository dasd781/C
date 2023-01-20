#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	int x;
	cout << "Введите число для проверки на кратность :";
	cin >> x;

	int arr[] = { 5, 4, 3, 4, 9 };
	int arrayLength = sizeof(arr) / sizeof(arr[0]);
	int count = 0;// изначальное количество кратных элементов
	for (int i = 0; i < arrayLength; ++i)
	{
		if (arr[i] % x == 0) //проверяем кратность числу х
		{
			++count;
		}
	}
	cout << "В массиве количество чисел кратных" << x << "равно:";
	cout << count << endl;
	return 0;

}
