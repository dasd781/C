#include"AVL.h"


//������� ��� ������ � ������� ���������
size_t AVL::height(Node* node)
{
	return node ? node->height : 0;
}
//������� ������� ����� 
int AVL::bfactor(Node* node)
{
	return height(node->right) - height(node->left);
}
// ����������� ������
void AVL::fix_height(Node* node)
{
	size_t h_left = height(node->left);
	size_t h_right = height(node->right);

	node->height = (h_left > h_right ? h_left : h_right) + 1;
}
// ������� �������
Node* AVL::rotateRight(Node* node)
{
	Node* q = node->left;

	node->left = q->right;
	q->right = node;
	fix_height(node);
	fix_height(q);

	return q;
}
// ������� ������
Node* AVL::rotateLeft(Node* node)
{
	Node* q = node->right;

	node->right = q->left;
	q->left = node;
	fix_height(node);
	fix_height(q);

	return q;
}
// ��������� ������������ ������ ������ ����
Node* AVL::balance(Node* const node)
{
	// ��������� ���������� ������ ��� ����
	fix_height(node);

	// ����������� ������ � ����������� �� ������� ������������
	if (bfactor(node) == 2)
	{
		if (bfactor(node->right) < 0)
			node->right = rotateRight(node->right);
		return rotateLeft(node);
	}

	if (bfactor(node) == -2)
	{
		if (bfactor(node->left) > 0)
			node->right = rotateLeft(node->left);
		return rotateRight(node);
	}

	// ������������ �� �����
	return node;
}
