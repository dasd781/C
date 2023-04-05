#include"Node.h"
#include"List.h"



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

}
