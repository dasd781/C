#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

/*int main()
{
	const int count = 5;
	int* n = (int*)calloc *sizeof(int));
	for (int i = 0; i < count; i++)
		std::cout << n[i] << " ";
	std::cout << std::endl;
	free(n);

	return 0;
}*/

int main()
{
	//определяем размер массива в элементах
	int arr_size = 10;
	// выделяем память под массив из 10 int
	int* arr = int*malloc(sizeof(int) * arr_size);
	// обнуляем sizeof(int)*arr_size=4*10=40 байт 
	//на начало которых указывает arr
	memset(arr, 0, sizeof(int) * arr_size);
}

