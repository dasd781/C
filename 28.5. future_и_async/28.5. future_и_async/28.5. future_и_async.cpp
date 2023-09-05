#include <future>
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

/*bool threadFunc() {
    // do something
    return true;
}

int main() {
    future<bool> f = async(threadFunc);

    this_thread::sleep_for(chrono::seconds(2));
    f.get(); // немедленное возвращение управления
    return 0;
}*/

/*bool threadFunc()
{
    // do something
    this_thread::sleep_for(chrono::seconds(3));
    return true;
}

int main()
{
    future < bool > f = async(launch::async, threadFunc);

    if (f.valid())
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;

    f.get();

    if (f.valid())
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;
    return 0;
} */

//Пример кода ниже демонстрирует работу метода future::wait:

bool threadFunc() {
    // do something
    this_thread::sleep_for(chrono::seconds(3));
    return true;
}

int main() {
    future<bool> f = async(launch::async, threadFunc);

    f.wait();

    if (f.valid())
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;

    return 0;
}

// future_status::deferred — поток вовсе не был запущен (возвращается сразу);
//future_status::ready — поток завершил работу(возвращается в течение заданного времени ожидания);
//future_status::timeout — поток был запущен, но ещё не завершил работу(возвращается по окончании времени ожидания).