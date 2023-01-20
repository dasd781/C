#include<iostream>
using namespace std;

struct Module // Описание структуры модуля
{
	const char* moduleName;//Имя модуля
	short tasksCount; //Количество задач в модуле
	int unitsCount; //  Количество юнитов в модуле
	long mjduleSize; // Размер модуля в страницах
};

void displayModule(Module m) //Функция принемающая в себя экземпляр структуры модуля
{
	cout << "Имя модуля : " << m.moduleName << endl;
	cout << "Количество задач : " << m.tasksCount << endl;
	cout << " Количество юнитов : " << m.unitsCount << endl;
	cout << "Размер модуля в страницах : " << m.mjduleSize << endl;
  }
int main()
{
	Module m{ " Функции ", 10, 5, 15 }; //Обьявление модуля и заполнение данных
	displayModule(m);//  Вызов функции отоброжающей информацию о модуле

	return 0;
}