#include<iostream>

int powFunc(int n, int m)
{
	int r = 1;
	for (int k = 1; k <= n; ++k)
		r *= m;
	return r;
}
int main()
{
	std::cout << powFunc(2, 10) << std::endl;
}