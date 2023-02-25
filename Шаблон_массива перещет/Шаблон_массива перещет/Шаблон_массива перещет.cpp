#include<iostream>
using namespace std;

int return7()
{
	return 7;
}

void DopPrint()
{
	std::cout << "dop print" << endl;
}

template<class T>
T averdge(T* array, int length)
{
	T sum = 0;
	for (int count = 0; count < length; ++count)
		sum += array[count];

	sum /= length;
	return sum;
}

int main()
{   int array1[] = { 7,5,1,3,9 };
	std::cout << averdge(array1, 5) << '\n';

	DopPrint();

	return7();
	std::cout << return7() + 3 << std::endl;
	double array2[] = { 4.25, 5.37, 8.44, 9.25 };
	std::cout << averdge(array2, 4) << '\n';

	return 0;
}