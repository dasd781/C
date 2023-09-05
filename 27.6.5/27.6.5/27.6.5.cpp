#include <mutex>
#include <thread>
#include <iostream>
struct Account
{
	explicit Account(int money) : money{ money }
	{
	}

	int money;
	std::mutex m;
};

void add(Account& acc, int num)
{
	acc.m.lock();
	acc.money += num;
	acc.m.unlock();
}

int main()
{
	Account acc1(100);
	Account acc2(50);
	std::thread t1(add, std::ref(acc1), 10);
	std::thread t2(add, std::ref(acc2), 5);
	t1.join();
	t2.join();
	std::cout << acc1.money << std::endl;
	std::cout << acc2.money << std::endl;
}