#include"Node.h"
#include"List.h"

using namespace std;

void List::push_back(int data)
{
	//������� ����� ����
	Node* node = new Node(data);
	//���� ������ ���� �� ���������� ����
	if (m_head == nullptr)
	{
		m_head = node;
		return;
	}
	// � ����� ���� ��������� ������� ������
	Node* last = m_head;
	while (last->m_next != nullptr)
	{
		last = last->m_next;
	}
	// ��������� ��������� next ����� ���� 
	//�� ��������� �� ����� ����
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
	//������� ����� ����
	Node* newNode = new Node(data);
	if (m_head == nullptr)
	{
		// ���� ������ ���� ����� ���� � ����� ������� ������
		m_head = newNode;
		return;
	}
	if (pos == 0)
	{
		//������� ������ - ������� � ������ ������
		newNode->m_next = m_head;
		m_head = newNode;
		return;
	}
	int currPos = 0;

	Node* current = m_head;
	//� ����� ���� �� ������ , ���� ������ �� ��������
	// ��� ���� �� ������ �� �������
	while (currPos < pos - 1 && current->m_next != nullptr)
	{
		current = current->m_next;
		currPos++;
	}
	//������ ��������� �� ��������� ���� �� ��������� 
	// �� ����� ����
	Node* next = current->m_next;
	current->m_next = next;

}

void List::deleteNode(int data)
{
	Node* temp = m_head;
	Node* prev = nullptr;

	//������� ������ �������� ������ ������
	if (temp && temp->m_data == data)
	{
		m_head = temp->m_next;
		delete temp;
		return;
	}
	//���� �� ������ ���� �� ������ ���� � ��������� ������ ������ �����
	while (temp && temp->m_data != data)
	{
		prev = temp;
		temp = temp->m_next;
	}
	//���� ���� �� ������ ����������
	if (!temp)
		return;
	//������ ��������� ���������� ���� ��� ����������� ����
	// �� ���� ��������� �� ��������� ����� � ������� ����� �������
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


		 // ������� ������ �������� ������ ������
		 if (temp && position == 1)
		 {
			 m_head = temp->m_next;
			 delete temp;
			 return;
		 }
		 // ���� �� ������, ���� �� ������ ���� �� number of ������, ������ position
		 int currentPosition = 1;
		 while (temp && currentPosition != position)
		 {
			 prev = temp;
			 temp = temp->m_next;
			 currentPosition++;
		 }
		 // ���� ���� �� ������, ����������
		 if (!temp)
			 return;
		 // ������ ��������� ���������� ���� ��� ����������� ���� �� ����, ��������� �� ��������� �����, � ������� ���� � �������
		 prev->m_next = temp->m_next;
		 delete temp;
    
 // ��� ���
} 
