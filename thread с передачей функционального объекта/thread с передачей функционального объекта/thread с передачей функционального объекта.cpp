
#include<iostream>
#include<string>
#include<thread>


class Task
{
public:
	void operator() (const std::string msg)
	{
		std::cout << msg << std::endl;
	}

};

int main()
{
	Task task;
	std::thread t(task, "Hello < world !");
	t.join();
	return 0;
}