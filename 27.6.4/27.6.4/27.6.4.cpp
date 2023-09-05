#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex;

int main() {
    std::thread th1([]() {
        mutex.lock();
        std::cout << "Whoa! Thread #1";
        std::cout << std::endl;
        });

    std::thread th2([]() {
        mutex.lock();
        std::cout << "Whoa! Thread #2";
        std::cout << std::endl;
        });

    std::thread th3([]() {
        mutex.lock();
        std::cout << "Whoa! Thread #3";
        std::cout << std::endl;
        });

    th1.join();
    th2.join();
    th3.join();

    return 0;
}