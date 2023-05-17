#include<iostream>
#include<list>
#include<iterator>
using namespace std;

int main()
{
	list <int> lst;
	list <int> lst1{ 0,1,2,3,4,5 };
	//методы для получения размера списка — size и 
	//проверки, пуст ли список, — empty
	cout << "is lst empty: " << lst.empty() << endl;
	cout << "is lst1 empty: " << lst1.empty() << endl;

	cout << "lst size: " << lst.size() << endl;
	cout << "lst1 size: " << lst1.size() << endl;

	//Для доступа к первому и последнему элементам есть методы front() и back()
	cout << "lst front: " << lst.front() << endl;
	cout << "lst back: " << lst.back() << endl;

	//Обойти список можно с помощью итераторов списка или range based for loop
	for (int i : lst) {
		cout << i << " ";
	}

	cout << endl;

	list<int>::iterator it = lst.begin();

	while (it != lst.end()) 
	{
		if (*it == 3)
		{
			cout << "found 3!" << endl;
			break;
		}
		++it;
	}

	//итератор списка не поддерживает оператор сложения и вычитания
	list<int>::iterator it = lst.begin();

	cout << "element at index 2: " << *(it + 2) << endl; // ошибка компиляции

	//найти расстояние между итераторами, мы можем воспользоваться функцией
	//distance(InputIt first, InputIt last) из заголовочного файла <iterator>
	list<int>::iterator it = lst.begin();
	list<int>::iterator it2;

	while (it != lst.end()) 
	{
		if (*it == 3) 
		{
			it2 = it;
			break;
		}
		++it;
	}

	cout << "distance between begin and it2: " << std::distance(it2, lst.begin()) << endl;


	//Список позволяет вставить элемент в конец, начало и 
	//произвольное место в списке.

		/*push_back — вставляет элемент в конец списка.
		push_front — вставляет элемент в начало списка.
		pop_front — удаляет элемент в начале списка.
		pop_back — удаляет элемент в конце списка. */

		list<int> lst;
	lst.push_back(5);
	lst.push_front(1);

	for (int i : lst)
	{
		cout << i << endl;
	}

	lst.push_front(9);
	lst.pop_back();
	lst.pop_front();

	for (int i : lst)
	{
		cout << i << endl;
	}

	return 0;
}
