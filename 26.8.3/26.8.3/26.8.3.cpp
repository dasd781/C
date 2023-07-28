#include <iostream>
#include <string>
#include <thread>

voidcalc_sum(int n)
{
    int s = 0;
    for (int i = 0; i <= n; i++)
    {
        s += i;
    }
    std::cout << s << std::endl;
}

int main()
{
    std::thread t(calc_sum, 5);


    return 0;
}