#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	for (int i = 0; i <= 100; ++i)
	{
		if (i % 2 != 0)
		{
			continue; // переходим на следующую этерацию цикла, пропуская нечетные числа
		}
		sum += i;
	}
	cout << sum;

	return 0;

}
