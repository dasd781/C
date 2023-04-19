#include"Stack.h"


//Операции isEmpty и isFull - 
//два метода, которые показывает пустой или полный стек
bool Stack::isEmpty()
{
	return m_top < 0;
}
bool Stack::isFull()
{
	return m_top >= (MAX - 1);
}

//Операция push кладет на вершину 
// новый элемент стека и возвращает результат 
//успешности операции

bool Stack::push(int x)
{
	//если стек полон выводим сообщение 
	//на консоль и возвращаемся
	if (isFull())
	{
		cout << "Steck Overflow";
		return false;
	}
	else
		//увеличиваем значение вершины стека 
		//и кладем на вершину стека данные
	{
		++m_top;
		m_items[m_top] = x;
		return true;
	}
}
//Операция pop снимает с вершины стека последний элемент
//и возвращает его пользователю

int Stack::pop()
{
	//если стек пуст, 
	//выводим сообщение и возращаем значение 0
	if (isEmpty())
	{
		cout << "Stack Underflow";
		return 0;
	}
	else
		//абираем значение вершины стека, уменьшаем 
		//значение вершины стек на 1 и возращаем 
		//значение
	{
		int x = m_items[m_top];
		--m_top;
		return x;
	}
}
//операция peek, которая возвращает элемент
//с вершины стека без его удаления:

int Stack::peek()
{
	//если стек пуст возвращаемся
	if (isEmpty())
	{
		cout << "Stack is Empty";
		return 0;
	}
	else
		//возвращаем значение вершины 
		//стека без удаления данных
	{
		int x = m_items[m_top];
		return x;
	}
}