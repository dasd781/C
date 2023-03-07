#include<iostream>
#include<Cstring>
using namespace std;

class mstring
{
public:
	explicit mstring(const char* str)
	{
		cout << "string constructed" << str << endl;
		_size = strlen(str) + 1;
		_string = new char[_size];
		strcpu(_string, str);
	}
	mstring(const mstring& other)
	{
		cout << "string copy constructed" << other._string << endl;
		_string = new char[other._size];
		strcpu(_string, other._string);
		_size = other._size;
	}

};
