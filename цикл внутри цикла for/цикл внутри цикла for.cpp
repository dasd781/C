#include<iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 5; i++)//цикл для подщета строк
	{
		for (int j = 0; j < 5; j++)//вложенный цикл для отрисовки строк
		{
			cout << "#";
		}
		cout << endl;
	}
	return 0;
}
