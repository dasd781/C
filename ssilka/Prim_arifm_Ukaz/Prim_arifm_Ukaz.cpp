#include<iostream>
using namespace std;

int main() {
	int n = 10;

	int *ptr = &n;
	std::cout << "address = " << ptr << "\tvalue = " << *ptr << std::endl;

	ptr++;
	std::cout << "address = " << ptr << "\tvalue = " << *ptr << std::endl;

	ptr--;
	std::cout << "address = " << ptr << "\tvalue = " << *ptr << std::endl;

	return 0;