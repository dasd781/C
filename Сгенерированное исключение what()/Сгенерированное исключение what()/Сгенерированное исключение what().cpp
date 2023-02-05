/*#include<iostream>
#include<exception>
using namespace std;

class BadDivision : public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR : Bad Division Arguments";
	}
};*/

#include<iostream>
#include<exception>
using namespace std;

class BadDivision : public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR : Bad Division Arguments ! ";
	}
};
int Divide(int a, int b)
{
	if (b == 0)
	{
		throw BadDivision();
	}
	return a / b;
}
int main()
{
	int a = 4;
	int b = 0;
	try
	{
		int result = Divide(a, b);
		cout << "Division : " << result << endl;
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	return 0;
}