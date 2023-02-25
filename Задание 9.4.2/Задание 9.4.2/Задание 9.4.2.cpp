#include<iostream>
using namespace std;

int main()
{
    int* ptr = new int[3];

    for (int i = 0; i < 3; ++i)
    {
        ptr[i] = i;
    }
 
    delete[] ptr;
    return 0;
}