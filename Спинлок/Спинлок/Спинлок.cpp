#include <atomic>
#include <thread>
#include <iostream>

struct Spinlock
{
    std::atomic<bool> lock_ = { false };

    void lock()
    {
        while (lock_.exchange(true))
        {
            ;
        }
    }

    void unlock()
    {
        lock_.store(false);
    }
};

Spinlock slock;
static int counter = 0;

void add()
{
    for (int i = 0; i < 100000; i++)
    {
        slock.lock();
        std::this_thread::sleep_for(std::chrono::seconds(3)); // для демонстрации нагрузки на процессор
        counter++;
        slock.unlock();
    }
}

void subtraction()
{
    for (int i = 0; i < 100000; i++)
    {
        slock.lock();
        counter--;
        std::this_thread::sleep_for(std::chrono::seconds(3)); // для демонстрации нагрузки на процессор
        slock.unlock();
    }
}

int main()
{
    std::thread th1(add);
    std::thread th2(subtraction);

    th1.join();
    th2.join();

    std::cout << counter << std::endl;

    return 0;
}