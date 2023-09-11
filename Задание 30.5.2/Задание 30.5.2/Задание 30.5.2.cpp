
/*
класс ThreadPool из второго юнита так, чтобы он получал фьючерс с помощью std::promise (промиса).
Нужно организовать внутреннюю логику так, чтобы каким-то образом задействовать промис вместо std::packaged_task.

*/










#pragma once

#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>
#include <future>

using namespace std;

typedef function<void()> task_type;
typedef future<void> res_type;
typedef void (*FuncType) (int, int);

class ThreadPool {
public:
    void start();
    void stop();
    res_type push_task(FuncType f, int arg1, int arg2);
    void threadFunc();
private:
    struct TaskWithPromise {
        task_type task;
        promise<void> prom;
    };
    vector<thread> m_threads;
    queue<TaskWithPromise> m_task_queue;
    mutex m_locker;
    condition_variable m_event_holder;
    volatile bool m_work;
};

res_type ThreadPool::push_task(FuncType f, int arg1, int arg2) {
    lock_guard<mutex> l(m_locker);

    TaskWithPromise twp;
    twp.task = [=] {
        f(arg1, arg2);
        };

    res_type res = twp.prom.get_future();

    m_task_queue.push(move(twp));
    m_event_holder.notify_one();

    return res;
}
void ThreadPool::threadFunc() {
    while (true) {
        TaskWithPromise task_to_do;
        {
            unique_lock<mutex> l(m_locker);
            if (m_task_queue.empty() && !m_work)
                return;
            if (m_task_queue.empty()) {
                m_event_holder.wait(l, [&]() {return !m_task_queue.empty() || !m_work; });
            }
            if (!m_task_queue.empty()) {
                task_to_do = move(m_task_queue.front());
                m_task_queue.pop();
            }
        }
        if (task_to_do.task) {
            task_to_do.task();
            task_to_do.prom.set_value();
        }
    }
}