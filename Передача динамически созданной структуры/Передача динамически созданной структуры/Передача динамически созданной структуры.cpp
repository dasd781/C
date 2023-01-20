#include<iostream>
using namespace std;

struct Module
{
	const char* moduleName;//Имя модуля
	short tasksCount; //Количество задач в модуле
	int unitsCount; //Количество юнитов в модуле
	long voduleSize; // Размер модуля в страницах
};

void displayModule(Module* m)// Функция теперь принемает указатель
{
	cout << "Имя модуля :" << m->moduleName << endl; //Получаем доступ к полю структуры созданной
	//динамически при помощи оператора new
	cout << "Количество задач : " << m->tasksCount << endl;
	cout << "Количество юнитов : " << m->unitsCount << endl;
	cout << "Размер модуля в страницах :" << m->voduleSize << endl;
   }
int main()
{
	Module* m = new Module{ "Функция" , 15, 5, 10 };//Использование списка иницилизации вместе 
	// с оператором new
	displayModule(m);
	delete m;
	return 0;

}