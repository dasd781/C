#include<iostream>
using namespace std;

class Divider
{
private:
	int _number;
	int* _cache;
public:
	Divider(int num) : _number(num)
	{
		cout << "allocating cache" << endl;
		_cache = new int[10];
		cout << "cache allocated" << endl;
		if (num == 0)
		{
			throw "Divider can not be 0 ! ";
		}
	}
	~Divider()
	{
		cout << "Divider destructed" << endl;

		delete[] _cache;
		cout << "deleted cache" << endl;
		cout << "Dividre destructed " << endl;
	}
};
int main()
{
	try
	{
		Divider d(0);
	}
	catch (const char* exсeption)
	{
		cout << "Exception caught :" << exception << endl;
	}
	return 0;
}