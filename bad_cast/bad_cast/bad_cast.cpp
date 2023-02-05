#include<iostream>
#include<typeinfo>//заголовочный файл где обьявлен bad_cast
using namespace std;

struct Foo 
{virtual ~Foo(){} };
struct Bar
{virtual ~Bar(){} };

int main()
{
	Bar b;
	try
	{
		Foo& f = dynamic_cast<Foo&>(b);
	}
	catch (const bad_cast& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}