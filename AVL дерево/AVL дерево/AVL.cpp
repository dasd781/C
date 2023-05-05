#include"AVL.h"


//обертка для работы с пустыми деревьями
size_t AVL::height(Node* node)
{
	return node ? node->height : 0;
}
//находим разницу высот 
int AVL::bfactor(Node* node)
{
	return height(node->right) - height(node->left);
}
// Исправление высоты
void AVL::fix_height(Node* node)
{
	size_t h_left = height(node->left);
	size_t h_right = height(node->right);

	node->height = (h_left > h_right ? h_left : h_right) + 1;
}
// Поворот направо
Node* AVL::rotateRight(Node* node)
{
	Node* q = node->left;

	node->left = q->right;
	q->right = node;
	fix_height(node);
	fix_height(q);

	return q;
}
// Поворот налево
Node* AVL::rotateLeft(Node* node)
{
	Node* q = node->right;

	node->right = q->left;
	q->left = node;
	fix_height(node);
	fix_height(q);

	return q;
}
// выполняем балансировку дерева вокруг узла
Node* AVL::balance(Node* const node)
{
	// вычисляем правильную высоту для узла
	fix_height(node);

	// Балансируем дерево в зависимости от фактора балансировки
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

	// балансировка не нужна
	return node;
}
