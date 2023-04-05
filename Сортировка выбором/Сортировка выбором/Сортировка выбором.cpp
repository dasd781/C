#include <iostream>
using namespace std;
void choice_sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_ind = i;
		for (int j = 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				min_ind = j;
			}
		}
		if (i != min_ind) {
			int temp = arr[i];
			arr[i] = arr[min_ind];
			arr[min_ind] = temp;
		}
	}
}
int main() {
	int arr[]{ 5,8,4,6,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	choice_sort(arr, n);
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}