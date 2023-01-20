#include<iostream>
#include<stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Введите два числа !" << endl;
		return 1;
	}
	float a = atof(argv[1]);
	float d = atof(argv[2]);
	cout << a * d << endl;
	return 0;
}
