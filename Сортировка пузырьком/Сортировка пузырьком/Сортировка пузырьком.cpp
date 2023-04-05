#include <iostream>
using namespace std;
void bubble_sort(int* arr, int n) 
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++)
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}
int main() {
	int arr[]{ 10,23,54,2,42,43 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, n);
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}