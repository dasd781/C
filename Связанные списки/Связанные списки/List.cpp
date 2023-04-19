#include"Node.h"
#include"List.h"

using namespace std;

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
	//в цикле идем по списку , пока список не кончится
	// или пока не дойдем до позиции
	while (currPos < pos - 1 && current->m_next != nullptr)
	{
		current = current->m_next;
		currPos++;
	}
	//меняем указатель на следующий узел на указатель 
	// на новый узел
	Node* next = current->m_next;
	current->m_next = next;

}

void List::deleteNode(int data)
{
	Node* temp = m_head;
	Node* prev = nullptr;

	//крайний случай удаления начала списка
	if (temp && temp->m_data == data)
	{
		m_head = temp->m_next;
		delete temp;
		return;
	}
	//идем по списку пока не найдем узел с значением данных равным ключу
	while (temp && temp->m_data != data)
	{
		prev = temp;
		temp = temp->m_next;
	}
	//если узел не найден возвращаем
	if (!temp)
		return;
	//меняем указатель следующего узла для предудущего узла
	// на узел следующий за удаленным узлом и удаляем узелс данными
	prev->m_next = temp->m_next;
	delete temp;
}

void List::deleteNode(int position) 
{ 
    struct Node* temp;
 
    struct Node* p = m_head;
 
    int count = 0;
 
  
    if (position == 0) 
    {
 
       m_head = p->m_next;
      
 
    } 
    else
    {
 
      while (count < position-1 && p != nullptr) 
      
 
          p = p->m_next;
     }
 
     temp = p->m_next;
     p->m_next = temp->m_next;
 
   
 
     m_head = p;

	 void List::deleteNode(int position)
	 {
		 if (position < 2)
		 {
			 return;
		 }

		 Node* temp = m_head;
		 Node* prev = nullptr;


		 // крайний случай удаления начала списка
		 if (temp && position == 1)
		 {
			 m_head = temp->m_next;
			 delete temp;
			 return;
		 }
		 // идем по списку, пока не найдем узел со number of данных, равных position
		 int currentPosition = 1;
		 while (temp && currentPosition != position)
		 {
			 prev = temp;
			 temp = temp->m_next;
			 currentPosition++;
		 }
		 // если узел не найден, возвращаем
		 if (!temp)
			 return;
		 // меняем указатель следующего узла для предыдущего узла на узел, следующий за удаляемым узлом, и удаляем узел с данными
		 prev->m_next = temp->m_next;
		 delete temp;
    
 // ваш код
} 
