#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int a = 5;
    auto f = [a](int x, int y) { return a + x + y; };
    std::cout << f(2, 3) << std::endl;
    return 0;
}


/*
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int a = 5;
    auto f = [a](int x, int y) { return a + x + y; };
    std::cout << f(2, 3) << std::endl;
    return 0;
}

*/