#include "module.h"
#include <iostream>

using namespace std;

int main()
{

	Module m("Functions", 10, 5, 15);
	m.displayModule();
	++m;
	m.displayModule();
	++m;
	m.displayModule();
	--m;
	m.displayModule();
	return 0;
}
