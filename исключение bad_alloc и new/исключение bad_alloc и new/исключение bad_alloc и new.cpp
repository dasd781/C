#include<iostream>

using namespace std;
struct BigStruct
{
	double bigStuff[400000];
};
int main()
{
	BigStruct* bg;
	try
	{
		bg = new BigStruct[400000];
	}
	catch (bad_alloc& ba)
	{
		cout << "bad_alloc caught !" << endl;
		cout << ba.what() << endl;
	}
	return 0;
}