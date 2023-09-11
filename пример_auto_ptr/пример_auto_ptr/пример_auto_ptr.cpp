#include <memory>
using namespace std;


class A {
public:
    void someFunc() {

    }
};

int main()
{
    {
        auto_ptr<int> sp(new int(5));
        *sp = 6;
    } // ~sp, вызов delete на int внутри
    A* a = new A; // сырой указатель
    auto_ptr<A> sp(a);
    sp->someFunc();
    sp.release();
} //~sp, вызов delete a внутри


