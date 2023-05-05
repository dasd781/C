#include"�� ������.h"
#include<iostream>

//insert
void RBTree::insert(int key)
{
    Node* z = new Node(key);
    insert(root, z);
};

void RBTree::insert(Node* root, Node* node)
{
    Node* currentNode = root;
    Node* parentNode = nullptr;

    while (currentNode != nullptr)
    {
        parentNode = currentNode;
        if (node->key > currentNode->key)
            currentNode = currentNode->right;
        else
            currentNode = currentNode->left;
    }
    node->parent = parentNode;

    if (parentNode != nullptr)
    {
        if (node->key > parentNode->key)
            parentNode->right = node;
        else
            parentNode->left = node;
    }
    else
        root = node;

    node->color = Red;
    InsertFixUp(root, node);
};
// �������� ������
Node* RBTree::search(int key)
{
    return search(root, key);
}

Node* RBTree::search(Node* node, int key) const
{
    if (node == nullptr || node->key == key)
        return node;
    else
        if (key > node->key)
            return search(node->right, key);
        else
            return search(node->left, key);
}
