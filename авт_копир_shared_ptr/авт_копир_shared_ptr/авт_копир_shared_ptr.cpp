#include <iostream>
#include <memory>

using namespace std;
weak_ptr<int> gw;

void f()
{
    if (!gw.expired())
    {
        cout << "gw is valid\n";
    }
    else
    {
        cout << "gw is expired\n";
    }
}

int main()
{
    {
        auto sp = make_shared<int>(42);
        gw = sp;

        f(); // объект sp существует при данном вызове
    }

    f(); // объект sp уже уничтожен при втором вызове вне первого блока кода
}