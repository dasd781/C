#include<iostream>
#include<string>
#include<thread>

void print_fact(int n)
{
	int fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}
	std::cout << fact << std::endl;
}

int main()
{
	std::thread t(print_fact, 5);
	return 0;
}