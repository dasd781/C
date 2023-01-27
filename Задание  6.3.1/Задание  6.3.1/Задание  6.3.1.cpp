#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Show()
    {
        cout << "Show Base Class" << endl;
    }

    void Say()
    {
        cout << "Say Base Class" << endl;
    }
};

class Derived : public Base
{
public:
    void Show()
    {
        cout << "Show Derived Class" << endl;
    }

    void Say()
    {
        cout << "Say Derived Class" << endl;
    }
};

int main()
{
    Derived derived;
    Base* pderived = &derived;

    derived.Say();
    pderived->Say();

    derived.Show();
    pderived->Show();

    return 0;
}