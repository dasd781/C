#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int s = 0;

    if (a <= 0)
    {
        a = 1;
    }

    s = a * b;
    cout << "площадь: " << s << endl;

    return 0;
}