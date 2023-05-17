#include <vector> 
#include <algorithm> 
#include <iostream> 
bool isOdd(int i)
{
    return i % 2 == 0;
}

bool Greater9(int i)
{
    return i > 9;
}


bool isNegative(int i)
{
    return i < 0;
}

void PrintNum(int i) {
    std::cout << ' ' << i;
}

int main()
{
    std::vector<int> v{ 10, 2, 4, 8 };

    if (std::all_of(v.cbegin(), v.cend(), isOdd))
    {
        std::cout << "All numbers are even\n";
    }

    if (std::any_of(v.begin(), v.end(), Greater9))
    {
        std::cout << "There are  elements greater than 9 in the range.\n";
    }

    if (std::none_of(v.begin(), v.end(), isNegative))
    {
        std::cout << "No numbers are negative\n";
    }

    std::for_each(v.begin(), v.end(), PrintNum);

    return 0;
}

