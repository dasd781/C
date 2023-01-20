#include<iostream>
#include "Choco.h"

using namespace study;
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	Module::Module("Шоколад", 1, 10, 10);
	ostream& operator<<(ostream & output, const Module & m);

	char b = 0;
	char s = 0;
	std::cout << "Что вы хотите купить?" << endl;
	std::cout << "b - Bounty,  s - Snickers" << endl;
	std::cin >> b;
	std::cin >> s;

	return 0;
}