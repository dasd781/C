#include <iostream>
#include <thread>
#include <shared_mutex>

class ActorInfo
{
public:
    void setInfo(const std::string& name, const std::string& surname)
    {
        shared_mutex.lock();
        this->name = name;
        std::this_thread::sleep_for(std::chrono::seconds(3));  // имитируем долгую обработку
        this->surname = surname;
        shared_mutex.unlock();
    }

    std::string getInfo()
    {
        shared_mutex.lock_shared();
        auto info = this->name + ' ' + this->surname;
        shared_mutex.unlock_shared();
        return info;
    }

private:
    std::string name = "";
    std::string surname = "";
    std::shared_mutex shared_mutex;
};

ActorInfo actor;

void writer(const std::string& name, const std::string& surname)
{
    actor.setInfo(name, surname);
}

void reader()
{
    std::cout << actor.getInfo() << std::endl;
}

int main()
{
    std::thread w1(writer, "Arnold", "Swarchenegger");
    std::thread r1(reader);
    std::thread w2(writer, "Bruce", "Willis");
    std::thread r2(reader);

    w1.join();
    r1.join();
    w2.join();
    r2.join();

    std::thread(reader).join();
}