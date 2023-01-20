#include <iostream>
using namespace std;

int main()
{
	bool a = false;
	bool b = true;
	if (a && b)
	{
		cout << "a is true b is true" << endl;
	}
	else if (a && !b)
	{
		cout << "a is true b is false" << endl;
	}
	else if (!a && b)
	{
		cout << "a is false b is true" << endl;
	}
	else
	{
		cout << "a is false b is false" << endl;
	}

	return 0;
}
