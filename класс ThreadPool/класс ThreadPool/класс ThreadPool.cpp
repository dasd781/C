#include <queue>
#include <future>
#include <condition_variable>
#include <vector>
#include<iostream>
using namespace std;

void taskFunc(int id, int delay);
// удобное определение для сокращения кода
typedef function<void()> task_type;
// тип указатель на функцию, которая является эталоном для функций задач
typedef void (*FuncType) (int, int);
// пул потоков
class ThreadPool {
public:
    // запуск
    void start();
    // остановка
    void stop();
    // проброс задач
    void push_task(FuncType f, int id, int arg);
    // функция входа для потока
    void threadFunc();
private:
    // потоки
    vector<thread> m_threads;
    // поддержка синхронизации очереди
    mutex m_locker;
    // очередь задач
    queue<task_type> m_task_queue;
    // для синхронизации работы потоков
    condition_variable m_event_holder;
    // флаг для остановки работы потоков
    volatile bool m_work;
};  
typedef void (*FuncType) (int, int);

void ThreadPool::start() {
    m_work = true;
    for (int i = 0; i < 4; i++) {
        m_threads.push_back(thread(&ThreadPool::threadFunc, this));
    }
}

void ThreadPool::stop() {
    m_work = false;
    m_event_holder.notify_all();
    for (auto& t : m_threads) {
        t.join();
    }
}
void ThreadPool::push_task(FuncType f, int id, int arg) {
    lock_guard<mutex> l(m_locker);
    task_type new_task([=] {f(id, arg); });
    m_task_queue.push(new_task);
    // оповещаем случайный поток о новой задаче
    m_event_holder.notify_one();
}

void ThreadPool::threadFunc() {
    while (true) {
        // обработка очередной задачи
        task_type task_to_do;
        {
            unique_lock<mutex> l(m_locker);
            if (m_task_queue.empty() && !m_work)
                // очередь пуста и взведен флаг — выходим
                return;
            if (m_task_queue.empty()) {
                // очередь пуста — ждем события
                m_event_holder.wait(l, [&]() {return !m_task_queue.empty() || !m_work; });
            }
            if (!m_task_queue.empty()) {
                // нужно снова проверить на пустоту, ведь могли
                // проснуться по !work
                task_to_do = m_task_queue.front();
                m_task_queue.pop();
            }
        }
        // выполняем задачу, вызвав функтор
        task_to_do();
    }
}
class RequestHandler {
public:
    RequestHandler();
    ~RequestHandler();
    // отправка запроса на выполнение
    void pushRequest(FuncType f, int id, int arg);
private:
    // пул потоков
    ThreadPool m_tpool;
};
RequestHandler::RequestHandler() {
    m_tpool.start();
}
RequestHandler::~RequestHandler() {
    m_tpool.stop();
}
void RequestHandler::pushRequest(FuncType f, int id, int arg) {
    m_tpool.push_task(f, id, arg);
}
// функция, выполняющая задачу
void taskFunc(int id, int delay) {
    // имитируем время выполнения задачи
    this_thread::sleep_for(chrono::seconds(delay));
    // выводим информацию о завершении
    unique_lock<mutex> l(coutLocker);
    cout << "task " << id << " made by thread_id " << this_thread::get_id() << endl;
}


int main()
{
    srand(0);
    for (int i = 0; i < 20; i++)
        taskFunc(i, 1 + rand() % 4);
    return 0;
}