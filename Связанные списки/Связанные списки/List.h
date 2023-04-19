#pragma once
#include"Node.h"

class List
{
public:
	List() : m_head(nullptr){}
	void push_back(int data);
	void push_front(int data);
	void insert(int pos, int data);
	void deleteNode(int data);
	void deleteNode(int position);
private:
	Node* m_head;
};
