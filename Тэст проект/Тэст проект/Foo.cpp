#include "Add.h"
#include "Foo.h"
#include <iostream>
using namespace  std;

void Foo()
{
    int arr[10]{ 0,1,2,3,4 };

    for (int i = 0; i < 10; i++)
    {
        int a = 5;
        int sum = Add(arr[i], a);
        cout << sum << endl;
    }
}