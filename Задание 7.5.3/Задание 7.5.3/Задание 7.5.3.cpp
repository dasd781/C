#include <iostream>
using namespace std;

int main()
{
    try
    {
        try
        {
            throw 42;
        }
        catch (int n)
        {
            cout << "Inner Exception Caught!" << endl;
            throw;
        }
    }
    catch (int x)
    {
        cout << "Outer Exception Caught!" << endl;
    }
    return 0;
}