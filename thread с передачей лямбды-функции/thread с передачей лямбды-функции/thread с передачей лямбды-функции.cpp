#include<iostream>
#include<string>
#include<thread>

int main()
{
	std::string str = "Hello, world !";
	std::thread t([str]() {std::cout << str << std::endl; });
	t.join();
	return 0;
}