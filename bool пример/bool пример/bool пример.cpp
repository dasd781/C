#include<iostream>

int main()
{
	std::cout << true << std::endl;//вместо true еденица
	std::cout << !true << std::endl;//вместо !true ноль

	bool b(false);
	std::cout << b << std::endl;// b - false (0)
	std::cout << !b << std::endl;//!b - true(1)

	std::cout << true << std::endl;
	std::cout << false << std::endl;

	std::cout << std::boolalpha;//выводим логические значения как "true" 
	// или "false"

	std::cout << true << std::endl;
	std::cout << false << std::endl;

	if (true)//это условие
		std::cout << "The conditeon is true !" << std::endl;
	else
		std::cout << "The conditeon is false !" << std::endl;

	
	if (b)
		std::cout << "b is true !" << std::endl;
	else
		std::cout << "b is false !" << std::endl;

	return 0;


}