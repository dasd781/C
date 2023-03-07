#include<iostream>
#include"add.h"
int add(int x, int y);// это нужно для того что бы main знал что функция add() определена в другом месте

int main()
{
	std::cout << "The cum of 3 and 4 is : " << add (3, 4) << std::endl;
	return 0;
}