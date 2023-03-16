
//алгоритм решения с квадратичной сложностью
int maxdiff1(int* array, size_t size)
{
	int max = array[1] - array[0];//начальная максимальная разница
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; i++)
			if (array[j] - array[i] > max) //считаем все разницы
				max = array[j] - array[i];//запоминаем максимальную
				return max;
}

// алгоритм имеет квадратичную сложность, а 
//в задаче требуется решение за линейное время
//Ниже приведён листинг такого алгоритма.

int maxdiff2(int* array, size_t size)
{
	int left = array[0];//начальный опорный левый элемент
	int max = array[1] - left;//начальная максимальная разница
	for (int i = 2; i < size; i++)
	{
		if (array[i] < left)
		{
			left = array[i];//если текущий элемент меньше левой границы 
			//то выбираем его как новую опорную границу
		}
		else if (array[i] - left > max)
		{
			max = array[i] - left;//запоминаем максимальную разницу
		}
	}
	return max;
}