#include"Node.h"
#include"List.h"



void List::push_back(int data)
{
	//создаем новый узел
	Node* node = new Node(data);
	//если список пуст то возвращаем узел
	if (m_head == nullptr)
	{
		m_head = node;
		return;
	}
	// в цикле ищем последний элемент списка
	Node* last = m_head;
	while (last->m_next != nullptr)
	{
		last = last->m_next;
	}
	// обновляем указатель next после узла 
	//на указатель на новый узел
	last->m_next = node;
}
void List::push_front(int data)
{
	Node* node = new Node(data);
	node->m_next = m_head;
	m_head = node;
}
void List::insert(int pos, int data)
{
	//создаем новый узел
	Node* newNode = new Node(data);
	if (m_head == nullptr)
	{
		// Если список пуст новый узел и будет началом списка
		m_head = newNode;
		return;
	}
	if (pos == 0)
	{
		//крайней случай - вставка в начало списка
		newNode->m_next = m_head;
		m_head = newNode;
		return;
	}
	int currPos = 0;

	Node* current = m_head;

}
