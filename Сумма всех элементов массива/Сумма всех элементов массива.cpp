#include<iostream>
using namespace std;

int main()
{
	int arr[] = { 500, 4, 24, 15, 100, 105 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	int sum = 0;
	for (int i = 0; i < arrLength;++i)
	{
		sum += arr[i];
	}
	cout << sum;

	return 0;
}