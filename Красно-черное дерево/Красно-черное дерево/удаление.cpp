#include"ВК дерево.h"
#include<iostream>

using namespace std;

void RBTree::remove(int key)
{
    Node* deletenode = search(root, key);
    if (deletenode != nullptr)
        remove(root, deletenode);
}

void RBTree::remove(Node*& root, Node* node)
{
    Node* child;
    Node* parent;
    Color color;
    // Узел слева и справа от удаляемого узла не пуст
    if (node->left != nullptr && node->right != nullptr)
    {
        Node* replace = node;
        // Находим узел-преемник (самый нижний узел правого поддерева текущего узла)
        replace = node->right;
        while (replace->left != nullptr)
        {
            replace = replace->left;
        }

        // Удаленный узел не является корнем
        if (node->parent != nullptr)
        {
            if (node->parent->left == node)
                node->parent->left = replace;
            else
                node->parent->right = replace;
        }
        else
            root = replace;
        // сохраняем нужные указатели заменяемого элемента и цвет
        child = replace->right;
        parent = replace->parent;
        color = replace->color;

        // Узел заменяется родительским узлом замены
        if (parent == node)
            parent = replace;
        else
        {
            // Есть дочерние узлы
            if (child != nullptr)
                child->parent = parent;
            parent->left = child;

            replace->right = node->right;
            node->right->parent = replace;
        }
        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;
        if (color == Black)
            removeFixUp(root, child, parent);

        delete node;
        return;
    }
    // Когда удаленный узел имеет только левый (правый) узел, находим дочерний узел удаленного узла
    if (node->left != nullptr)
        child = node->left;
    else
        child = node->right;

    parent = node->parent;
    color = node->color;
    if (child)
    {
        child->parent = parent;
    }
    // Удаленный узел не корень
    if (parent)
    {
        if (node == parent->left)
            parent->left = child;
        else
            parent->right = child;
    }
    // Удаленный узел - корень
    else
        RBTree::root = child;

    if (color == Black && root)
    {
        removeFixUp(root, child, parent);
    }
    delete node;

}