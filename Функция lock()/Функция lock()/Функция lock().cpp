#include <iostream>
#include <memory>
using namespace std;

void observe(weak_ptr<int> weak)
{
    if (shared_ptr<int> locked = weak.lock())
    {
        cout << "observe()  able to lock weak_ptr<>, value=" << *locked << endl;
    }
    else
    {
        cout << "observe() unable to lock weak_ptr<>" << endl;
    }
}

int main()
{
    weak_ptr<int> weak;
    cout << "weak_ptr<> not initialized" << endl;
    observe(weak);

    {
        shared_ptr<int> shared = make_shared<int>(42);
        weak = shared;
        cout << "weak_ptr<> initialized with shared_ptr" << endl;
        observe(weak);
    }

    cout << "shared_ptr<> has been destructed due to scope exit." << endl;
    observe(weak);
    return 0;
}