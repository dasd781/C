#include <iostream>
using namespace std;
int get_max(int* arr, int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++)

		if (arr[i] > max)
			max = arr[i];
	return max;
}

void countSort(int* arr, int n) {
	int* output = new int[n];
	int max = get_max(arr, n);
	int* count = new int[max + 1];
	for (int i = 0; i < max + 1; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[arr[i]]++;

	/*for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = 0; i < n; i++) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	*/
	int Size = 0;
	for (int i = 0; i < max + 1; i++)
	{
		for (int j = 1; j <= count[i]; j++)
		{

			output[Size] = i;
			Size++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}
	delete[] count;
	delete[] output;
}
int main() {
	int arr[] = { 2 ,0 ,2 ,3 ,7 ,5 ,6 ,0 ,0 ,0 ,0 ,0 };
	int arr2[] = { 2 ,0 ,2 ,3 ,7 ,5 ,6 ,0 ,0 ,0 ,0 ,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	countSort(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	countSort(arr2, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}