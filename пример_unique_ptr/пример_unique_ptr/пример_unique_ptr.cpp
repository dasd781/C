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
        unique_ptr<int> sp(new int(5));
        *sp = 6;
    } // ~sp, вызов delete на int внутри
    A* a = new A; // сырой указатель
    unique_ptr<A> sp(a);
    sp->someFunc();
    sp.release();
} //~sp, нет вызова delete a внутри