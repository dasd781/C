#include <thread>
#include <chrono>

using namespace std;
volatile static bool stopped = false;

bool checkInterrupted() {
    return stopped;
}

void interrupt() {
    stopped = true;
}

void threadFunc() {
    for (int i = 0; i < 100; i++)
    {
        this_thread::sleep_for(chrono::seconds(1));
        if (checkInterrupted()) return; // все время проверяем маркер прерывания
    }
}

int main()
{
    thread t(threadFunc);
    this_thread::sleep_for(chrono::seconds(2));
    interrupt(); // прерываем поток t
    t.join();
    return 0;
}