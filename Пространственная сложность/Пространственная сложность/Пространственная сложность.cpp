 

int max = array[0];//выделяем 4 байта для переменной max
for (
	int i = 1;// выделяем 4 байта для переменной i
	i < size;
	++if
	) 
{
	if (array[i] > max)
	{
		max = array[i];
	}
}


// задача 5


int uniq()
{
	int array[] ={1,2,1,7,8,9,1}//входной массив
	const int arr_size = sizeof(array) / sizeof(int);
	int uniq_counts[arr_size];//колличество каждого элемента
	int uniq_elements[arr_size];//массив уникальных элементов
	int uniq_counter = 0; //счетчик уникальных элементов

	// первая часть алгоритма ищем количество повторений для каждого
	for (int i = o; i < arr_size; i++)
	{
		int existing_index = -1;//переменная для запоминания

		//индекс найденного элемента
		for (int j = 0; j < uniq_counter; j++)
		{
			//поиск i-того элемента среди уже отобранных элементов
			if (uniq_elements[j] == array[i])
			{
				existing_index = j;
				uniq_counts[j]++;//увеличиваем колличество повторений на 1 раз
				break;
			}
		}
		if (existing_index == -1)
		{
			//если элемент еще не встречался запомним его
			uniq_elements[uniq_counter] = array[i];
			uniq_counts[uniq_counter] = 1;
			uniq_counter++;
		}

	}
	int max_uniq_count_index = 0;
	int max_uniq_count = uniq_counts[0];
	//вторая часть алгоритма среди посчитанных повторений ищем максимальное
	for (int i = 0; i < uniq_counter; i++)
	{
		if (max_uniq_count < uniq_counts[i])
			max_uniq_count_index = i;
	}
	return uniq_elements[max_uniq_count_index];
}