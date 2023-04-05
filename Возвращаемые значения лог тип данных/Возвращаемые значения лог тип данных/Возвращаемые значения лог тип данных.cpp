#include<iostream>

/*возвращаем true если x и y равны в противном случае
возвращаем false */
bool isEqual(int x, int y)
{
	return(x == y);//оператор == возвращает true  если 
	// x равно y в противном случае false

}

int main()
{
	std::cout << "Enter an integer : ";
	int x;
	std::cin >> x;

	std::cout << "Enter another integer : ";
	int y;
	std::cin >> y;

	if (isEqual(x, y))
		std::cout << x << " and " << y << " are equal " << std::endl;
	else
		std::cout << x << " end " << y << " are not equal " << std::endl;
	return 0;
}