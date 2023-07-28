#include<iostream>
#include<string>
#include<thread>

void write_msg(const std::string msg)
{
	std::cout << msg << std::endl;
}

int main()
{
	std::thread t(write_msg, "Hello, world!");
	t.join();
	return 0;
}