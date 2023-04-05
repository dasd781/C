#include<iostream>
using namespace std;

int getMax(int* arr, int n)//функция для нахождения мфксимального элемента массива
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
void countSort(int* arr, int n)
{

	// Шаг 0 (опционно) : Находим максимальный элемент массива если нам не известен m
	int max = getMax(arr, n);

	// Шаг 1 : Создаем массив частот размером m + 1 и временный массив размером n 
	int* count = new int[max + 1]; 
	int* output = new int[n];

	for (size_t i = 0; i < max + 1; i++)
		count[i] = 0;

	// Шаг 2 : Подщитываем частоты 
	for (size_t i = 0; i < n; i++)
		count[arr[i]]++;

	// Шаг 3 : Подсчитываем накопленные частоты
	for (size_t i = 1; i < max + 1; i++)
		count[i] += count[i - 1];

	// Шаг 4 : Записываем во временный массив значение входного
	// используя в качестве индекса во временном массиве значение накопленной частоты 
	for (size_t i = 0; i < n; i++)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (size_t i = 0; i < n; i++)
		arr[i] = output[i];

	delete[] count;
	delete[] output;
}

int main()
{
	int arr[] = { 3, 5, 1, 2, 1, 0, 5, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);//вычисляем размер массива
	countSort(arr, n);//вызываем сортировку

		for (int i = 0; i < n; i++)
		{
			//вывод отсортерованного массива на экран
			cout << arr[i] << "  ";
		}
	cout << endl;

	return 0;
}