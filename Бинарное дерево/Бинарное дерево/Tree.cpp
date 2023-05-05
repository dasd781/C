#include"Binary.h"
#include<iostream>

void BinaryTree::addInt(int newdata) 
{
    if (root == nullptr) 
    {
        // если дерево пустое, то новый элемент станет корнем
        root = new Node(newdata);
    }
    else {
        Node* current = root; // начинаем с корня
        Node* newNode = nullptr;
        while (newNode == nullptr)
        {
            if (current->data >= newdata)
            {
                // если элемент меньше текущего, идем влево
                if (current->leftChild != nullptr) {
                    current = current->leftChild;
                    continue;
                }
                // если левого узла нет, то нашли место для нового элемента
                newNode = new Node(newdata, current);
                current->leftChild = newNode;
            }
            else
            {
                // если элемент меньше текущего, идем вправо
                if (current->rightChild != nullptr) 
                {
                    current = current->rightChild;
                    continue;
                }
                // если правого узла нет, то нашли место для нового элемента
                newNode = new Node(newdata, current);
                current->rightChild = newNode;
            }
        }
    }
}

BinaryTree::Node* BinaryTree::findNodeByData(int finddata) {
    Node* current = root;
    while (current != nullptr) {
        if (current->data == finddata) {
            return current;
        }

        if (current->data > finddata) {
            current = current->leftChild;
        }
        else {
            current = current->rightChild;
        }
    }
    return nullptr;
}

void BinaryTree::delInt(int deldata) {
    Node* foundForDel = findNodeByData(deldata);
    if (foundForDel == nullptr)
        return; // такого целого числа нет в дереве
    // такое целое есть
    if (isLeaf(foundForDel)) { // если это лист, просто удалим его
        delLeaf(foundForDel);
    }
    else {
        // если не лист, то удаление сложнее
        if (foundForDel->leftChild == nullptr || foundForDel->rightChild == nullptr) {
            // случай, когда у узла только один дочерний
            delNodeWithOneChild(foundForDel);
        }
        else {
            // ищем правый элемент левого поддерева
            Node* mostright = foundForDel->leftChild;
            while (mostright->rightChild != nullptr)
                mostright = mostright->rightChild;

            // записали данные из правого вместо данных в удаляемом узле  
            foundForDel->data = mostright->data;

            // удалили правый элемент (он может содержать только левый узел)
            if (mostright->leftChild != nullptr)
                delNodeWithOneChild(mostright);
            else
                delLeaf(mostright);
        }
    }
}

// установка для родителя узла child нового дочернего
// узла newChild вместо child (для дальнейшего удаления узла)
void BinaryTree::setNewChild(Node* child, Node* newChild = nullptr) {
    Node* parent = child->parent;
    if (parent != nullptr) {
        if (parent->leftChild == child) {
            parent->leftChild = newChild;
        }
        else {
            parent->rightChild = newChild;
        }
    }
}

// удалить узел с одним дочерним узлом из дерева
void BinaryTree::delNodeWithOneChild(Node* delNode) {
    if (delNode->leftChild != nullptr) {
        // если имеет левый узел
        if (isRoot(delNode)) {
            root = delNode->leftChild;
        }
        else {
            setNewChild(delNode, delNode->leftChild);
        }
        delNode->leftChild->parent = delNode->parent;
        delNode->leftChild = nullptr;
    }
    else {
        // если правый узел
        if (isRoot(delNode)) {
            root = delNode->rightChild;
        }
        else {
            setNewChild(delNode, delNode->rightChild);
        }
        delNode->rightChild->parent = delNode->parent;
        delNode->rightChild = nullptr;
    }
    // удаляем узел
    delete delNode;
}
// удалить лист из дерева
void BinaryTree::delLeaf(Node* leaf) {
    if (isRoot(leaf)) { // случай, когда в дереве всего один корневой узел
        // забываем корень
        root = nullptr;
    }
    else {
        // обнуляем указатель на удаляемый узел у родителя
        setNewChild(leaf);
    }
    // удаляем листовой узел
    delete leaf;
}
