#pragma once

enum Color{Dlack, Red};

struct Node
{
	int key;
	Color color;
	Node* left;
	Node* right;
	Node* parent;
	Node(int k) : key(k), color(Red), parent(nullptr),
		left(nullptr), right(nullptr) {};
	Node* search(int key);
	Node* RBTree::remove(int key)
};
//Балансировка после удаления
// block 1void RBTree::removeFixUp(Node*& root, Node* node, Node* parent)
{
    Node* othernode;
    while ((!node) || node->color == Black && node != RBTree::root)
    {
        if (parent->left == node)
            // block 2
        {
            othernode = parent->right;
            if (othernode->color == Red)
            {
                othernode->color = Black;
                parent->color = Red;
                leftRotate(root, parent);
                othernode = parent->right;
            }
            // block 3
            else
            {
                // block 4 
                if (!(othernode->right) || othernode->right->color == Black)
                {
                    othernode->left->color = Black;
                    othernode->color = Red;
                    rightRotate(root, othernode);
                    othernode = parent->right;
                }
                othernode->color = parent->color;
                parent->color = Black;
                othernode->right->color = Black;
                leftRotate(root, parent);
                node = root;
                break;
                // block 5
            }
        }
        else
        {
            // block 6
            othernode = parent->left;
            if (othernode->color == Red)
            {
                othernode->color = Black;
                parent->color = Red;
                rightRotate(root, parent);
                othernode = parent->left;
            }
            // block 7
            if ((!othernode->left || othernode->left->color == Black)
                && (!othernode->right || othernode->right->color == Black))
            {
                othernode->color = Red;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (!(othernode->left) || othernode->left->color == Black)
                {
                    othernode->right->color = Black;
                    othernode->color = Red;
                    leftRotate(root, othernode);
                    othernode = parent->left;
                }
                othernode->color = parent->color;
                parent->color = Black;
                othernode->left->color = Black;
                rightRotate(root, parent);
                node = root;
                break;
            }
            // block 8
        }
    }
    if (node)
        node->color = Black;
}