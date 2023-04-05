

void merge(int* arr, int l, int m, int r)
{
	int nl = m - l + 1;
	int nr = r - m;

	// создаем временный массив
	int left[nl], right[nr];
	// копируем данные во временный массив
	for (int i = 0; i < nl; i++)
		left[i] = arr[l + i];
	for (int j = 0; j < nr; j++)
		right[j] = arr[m + 1 + j];

	int i = 0, j = 0;
	int k = l;// начало левой части

	while (i < nl && j < nr)
	{
		//записываем минимальные элементы обратно во входной массив
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			j++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	//записываем оставшиеся элементы правой части
	while (i < nl)
	{
		arr[k] = left[i];
		i++;
		k++;
	}
	//записываем оставшиеся элементы правой части
	while (j < nr)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
}