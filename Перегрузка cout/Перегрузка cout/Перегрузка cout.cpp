#include "module.h"
#include <iostream>

using namespace std;

int main()
{

	Module m1("Functions", 10, 5, 15);
	Module m2("Functions", 10, 5, 20);
	cout << m1;
	cout << m2;
	return 0;
}