#include <shared_mutex>
#include <iostream>
#include <queue>
#include <thread>

template <class T>
class MutexQueue
{
    std::queue<T> internal;
    std::shared_mutex mutex;

public:
    void push(const T& value)
    {
        std::unique_lock<std::shared_mutex> guard(mutex); // здесь нужна эксклюзивная блокировка, потому что ничего не должно помешать добавлению
        internal.push(value);
    }

    void pop()
    {
        std::unique_lock<std::shared_mutex> guard(mutex);
        if (!internal.empty())
            internal.pop();
    }

    auto size()
    {
        std::shared_lock<std::shared_mutex>(mutex); // параллельные вызовы size() не вызовут гонку данных, поэтому используем разделяемую блокировку
        auto result = internal.size();
        return result;
    }
};

void remove(int value)
{
    Node* prev, * cur;
    queue_mutex->lock();

    // здесь должна быть обработка случая пустого списка

    prev = this->head;
    cur = this->head->next;

    prev->node_mutex->lock();
    // здесь должна быть обработка случая удаления первого элемента
    queue_mutex->unlock();

    if (cur) // проверили и только потом залочили
        cur->node_mutex->lock();
    while (cur)
    {
        if (cur->value == value)
        {
            prev->next = cur->next;
            prev->node_mutex->unlock();
            cur->node_mutex->unlock();
            delete cur;
            return;
        }
        Node* old_prev = prev;
        prev = cur;
        cur = cur->next;
        old_prev->node_mutex->unlock();
        if (cur) // проверили и только потом залочили
            cur->node_mutex->lock();
    }
    prev->node_mutex->unlock();
}