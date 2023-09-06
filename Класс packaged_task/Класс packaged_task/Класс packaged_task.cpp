#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

void threadfunc(packaged_task<int()>& pt) {
    cout << "in threadFunc" << endl;
    // вызываем функцию, помещённую в упаковку    
    pt();
    // тут фьючерс перейдёт в готовое состояние
    this_thread::sleep_for(chrono::seconds(2));
    cout << "threadfunc finished" << endl;
}

int main()
{
    // объявляем упаковку
    packaged_task<int()> task([]() {
        cout << "packaged_task finished work" << endl;
        return 10;
        });
    // получаем фьючерс
    future<int> f = task.get_future();
    // запускаем поток, передав в него упаковку
    std::thread t(threadfunc, std::ref(task));

    // ждём результат по обычным правилам
    try {
        cout << "Future result: " << f.get() << endl;
        // что-то делаем с результатом
    }
    catch (...) {
        cout << "Some error in thread" << endl;
    }

    t.join();

    return 0;
}