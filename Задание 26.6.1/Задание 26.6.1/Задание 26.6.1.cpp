#include<iostream>
#include<vector>

int main()
{
	int x = 1;
	auto inc = [&x]() {++x};
	inc();
	std::cout << x << std::endl;
	return 0;
}