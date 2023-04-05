#include <iostream>
using namespace std;
void insert_sort(int* arr, int n)
{
	for (int j = 1; j < n; j++)
	{
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && key < arr[i]) 
		{
			arr[i + 1] = arr[i];
			arr[i] = key;
			i--;
		}
	}
}
int main() {

	int arr[]{ 12,54,87,2,54 };
	int n = sizeof(arr) / sizeof(arr[0]);
	insert_sort(arr, n);
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}