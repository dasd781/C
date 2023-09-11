#include <iostream>
#include <memory>

using namespace std;

class MyDeleter {
public:
    void operator()(int* p) {
        for (int i = 0; i < 5; i++)
            cout << p[i] << " ";
        delete[]p;
    }
};

int main()
{
    unique_ptr<int[], MyDeleter> sp(new int[5] {0, 1, 2, 3, 4}, MyDeleter());
    if (sp)
        sp[1] = 10;
}