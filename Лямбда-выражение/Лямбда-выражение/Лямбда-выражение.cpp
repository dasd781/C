#include<algorithm>
#include<iostream>
#include<vector>

bool isEven(int i)
{
	return (i % 2 == 0);
}

/*int main()
{
	std::vector<int> v{1, 2, 3, 4, 5, 8};
	std::cout << std::count_if(v.begin(), v.end(), isEven) << std::endl;
	return 0;
}*/
int main()
{
	std::vector<int> v{1, 2, 3, 4, 5, 8};
	auto isEven = [](int i) { return ((i % 2) == 0); };
	std::cout << std::count_if(v.begin(), v.end(), isEven) << std::endl;
	return 0;
}