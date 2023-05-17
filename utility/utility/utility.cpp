#include <iostream>
#include <utility>

using namespace std;
int main()
{
    pair<int, string> p1 = make_pair(1, "value");
    std::cout << "The value of p1 is "
        << "(" << p1.first << ", " << p1.second << ")";
    return 0;
}