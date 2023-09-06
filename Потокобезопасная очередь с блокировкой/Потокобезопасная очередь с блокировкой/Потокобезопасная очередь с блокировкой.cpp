#include <mutex>
#include <iostream>
#include <queue>
#include <thread>

template <class T>
class MutexQueue
{
    std::queue<T> internal;
    std::mutex mutex;

public:
    void push(const T& value)
    {
        mutex.lock();
        internal.push(value);
        mutex.unlock();
    }

    void pop()
    {
        mutex.lock(); // обязательно лочим мьютекс ДО проверки на пустоту очереди
        if (!internal.empty())
            internal.pop();
        mutex.unlock();
    }

    auto size()
    {
        mutex.lock();
        auto result = internal.size();
        mutex.unlock();
        return result;
    }
    // ... еще методы ... 
};