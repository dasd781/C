#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    // создали фьючерс   
    future<void> f = async(launch::async, []() {
        this_thread::sleep_for(std::chrono::seconds(1));
        cout << "thread work" << endl;
        });

    // проверили его готовность
    cout << "before wait future ready: " << (f.wait_for(std::chrono::seconds(0)) == future_status::ready) << endl;
    cout << "before wait future valid: " << f.valid() << endl;
    // подождали завершение потока
    f.wait();

    // проверка готовности и валидности после метода wait()
    cout << "after wait future ready: " << (f.wait_for(std::chrono::seconds(0)) == future_status::ready) << endl;
    cout << "after wait future valid: " << f.valid() << endl;

    f.get();

    // проверка валидности после get()
    cout << "after get, future valid: " << f.valid() << endl;

    return 0;
}

// Тут создаётся фьючерс с помощью std::async, куда передаётся лямбда-функция.