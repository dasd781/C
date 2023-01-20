#include<iostream>
using namespace std;

bool reset = false;
int counter = 3;
void AddOne()
{
    ++counter;
}

int main()
{
    int num = 0;
    {
        AddOne();
        int num = 1;
        num++;
        cout << num;
    }
    AddOne();
    cout << counter << endl;
    cout << num << endl;
    return 0;
}