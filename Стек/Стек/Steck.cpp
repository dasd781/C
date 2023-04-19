#include"Stack.h"


//�������� isEmpty � isFull - 
//��� ������, ������� ���������� ������ ��� ������ ����
bool Stack::isEmpty()
{
	return m_top < 0;
}
bool Stack::isFull()
{
	return m_top >= (MAX - 1);
}

//�������� push ������ �� ������� 
// ����� ������� ����� � ���������� ��������� 
//���������� ��������

bool Stack::push(int x)
{
	//���� ���� ����� ������� ��������� 
	//�� ������� � ������������
	if (isFull())
	{
		cout << "Steck Overflow";
		return false;
	}
	else
		//����������� �������� ������� ����� 
		//� ������ �� ������� ����� ������
	{
		++m_top;
		m_items[m_top] = x;
		return true;
	}
}
//�������� pop ������� � ������� ����� ��������� �������
//� ���������� ��� ������������

int Stack::pop()
{
	//���� ���� ����, 
	//������� ��������� � ��������� �������� 0
	if (isEmpty())
	{
		cout << "Stack Underflow";
		return 0;
	}
	else
		//������� �������� ������� �����, ��������� 
		//�������� ������� ���� �� 1 � ��������� 
		//��������
	{
		int x = m_items[m_top];
		--m_top;
		return x;
	}
}
//�������� peek, ������� ���������� �������
//� ������� ����� ��� ��� ��������:

int Stack::peek()
{
	//���� ���� ���� ������������
	if (isEmpty())
	{
		cout << "Stack is Empty";
		return 0;
	}
	else
		//���������� �������� ������� 
		//����� ��� �������� ������
	{
		int x = m_items[m_top];
		return x;
	}
}