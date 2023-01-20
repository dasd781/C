
#include <iostream>
using namespace std;

int main()
{
	int i = 1; // иницилизируем счетчик цикла
	int sum = 0; // иницилизируем счетчик суммы
	do {  // выполняем цикл
		sum += i;
		i++;
	} while (i <= 100); //пока выполняется условие
	cout << "Summ chisel ot 1 ddo 100" << sum << endl;
	return 0;
}
