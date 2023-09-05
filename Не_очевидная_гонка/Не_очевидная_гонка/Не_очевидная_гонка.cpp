#include <iostream>
#include <thread>

class Logger {
public:
    static void log() {
        std::cout << "Whoa!" << std::endl;
    }
};

int main() {

    std::thread th1([]() { Logger::log(); });
    std::thread th2([]() { Logger::log(); });
    std::thread th3([]() { Logger::log(); });

    th1.join();
    th2.join();
    th3.join();

    return 0;
}