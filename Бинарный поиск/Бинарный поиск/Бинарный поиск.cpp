


int binarySearch(int arr[], int I, int r, int x)
{
	if (r >= I)
	{
		/*
		I и r - левая и правая границы интервала
		(индекс интервала , тоесть для массива размером 10
		правая граница - идекс 9(10 - 1))
		*/
		int mid = I + (r - I) / 2;// находим середину интервала
		if (arr[mid] == x)
			return mid;//если попали в значение вернуть индекс
		if (arr[mid] > x) // если значение меньше середины
			//интервала повторить операцию с левым полуинтервалом 
			return binarySearch(arr, I, mid - 1, x);

		return binarySearch(arr, mid + 1, r, x);// в противном случае
		// повторить поиск для правого полуинтервала

	}
	return -1;
}

/*
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x) {
			return mid;
		} else if (arr[mid] > x) {
			return binarySearch(arr, l, mid - 1, x);
		} else {
			return binarySearch(arr, mid + 1, r, x);
		}
	} else {
		return -1;
	}
// ваш код
}

*/

