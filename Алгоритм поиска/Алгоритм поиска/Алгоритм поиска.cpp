#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

bool PositiveAndEven(int i)
{
    return (i > 0) && (i % 2 == 0);
}

int main()
{
    int n1 = 3;
    int n2 = 5;

    std::vector<int> v{ 0, 1, 2, 3, 4 };

    std::vector<int>::iterator result1 = std::find(std::begin(v), std::end(v), n1);
    std::vector<int>::iterator result2 = std::find(std::begin(v), std::end(v), n2);
    std::vector<int>::iterator result3 = std::find_if(std::begin(v), std::end(v), PositiveAndEven);

    if (result1 != std::end(v)) {
        std::cout << "v contains: " << n1 << '\n';
    }
    else {
        std::cout << "v does not contain: " << n1 << '\n';
    }

    if (result2 != std::end(v)) {
        std::cout << "v contains: " << n2 << '\n';
    }
    else {
        std::cout << "v does not contain: " << n2 << '\n';
    }

    if (result3 != std::end(v)) {
        std::cout << "v contains a positive even number: " << *result3 << '\n';
    }
    else {
        std::cout << "v does not contain positive even numbers\n";
    }
    return 0;
}