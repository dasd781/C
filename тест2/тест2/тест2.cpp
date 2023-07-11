#include <iostream>

int& func()
{
	int ar[] = { 1, 2, 3, 4, 5 };
	return ar[0];
}

int main()
{
	int i = func();
	std::cout << "i = " << i << std::endl;
	return 0;
}