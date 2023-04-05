#include<iostream>

int main()
{
	std::cout << " Input a keiboard : ";// предположим что 
	//пользователь ввел abcd

	char ch;
	std::cin >> ch;//ch = 'a', "bcd" остается в входном буфере
	std::cout << ch << "has ASCII code " << static_cast<int>(ch) << std::endl;

	//Обратите внимание следующий cin не просит пользователя
	//что либо пользователя ввести данные берутся из входного буфера
	std::cin >> ch;// ch = 'b' "cd" останется в буфере
	std::cout << ch << " has ASCII code " << static_cast<int>(ch) << std::endl;

	return 0;
}