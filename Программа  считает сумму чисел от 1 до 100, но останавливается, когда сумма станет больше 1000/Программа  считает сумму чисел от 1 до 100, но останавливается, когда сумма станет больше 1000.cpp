#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "");




	{
		int sum = 0;
		for (int i = 1; i <= 100; ++i)
		{
			if (sum > 1000)
			{
				cout << "что то написал по русски чтобы проверить сэелокаль" << sum << endl;
				break;
			}
			sum += i;
		}
		return 0;
	}
}