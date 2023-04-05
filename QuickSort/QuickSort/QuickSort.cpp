#include <iostream>
using namespace std;
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partiation(int* arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[j], &arr[i]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return(i + 1);
}
void quickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int pi = partiation(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);

	}
}

int main()
{
	int arr[]{ 6,24,65,22,46,689,3,12,76,1,1005,45,76,34 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}