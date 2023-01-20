#include <iostream>
using namespace std;

void doCalculate(bool& calc, int data)
{
	if (data % 2 == 0)
	{
		calc = true;
	}
}

int main()
{
	int data = 0;
	int array[5] = { 1,2,3,4,5 };


	for (int i = 0; i < 5; ++i)
	{
		bool needCalculate = false;
		doCalculate(needCalculate, array[i]);
		if (needCalculate)
		{
			data += array[i];
		}

	}

	cout << data << endl;
}

bool foobar(const float&, const float&)
{
	return  foobar ;
}
