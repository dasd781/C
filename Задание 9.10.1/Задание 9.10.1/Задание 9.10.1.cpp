#include <climits>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    cout << INT_MAX;
    int n = INT_MAX;
    int A[n];
    int i = 0;
    while (i < n)
        A[i] = rand() % 10;

    return 0;
}