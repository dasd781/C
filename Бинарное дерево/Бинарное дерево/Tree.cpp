#include"Binary.h"
#include<iostream>

void BinaryTree::addInt(int newdata) 
{
    if (root == nullptr) 
    {
        // ���� ������ ������, �� ����� ������� ������ ������
        root = new Node(newdata);
    }
    else {
        Node* current = root; // �������� � �����
        Node* newNode = nullptr;
        while (newNode == nullptr)
        {
            if (current->data >= newdata)
            {
                // ���� ������� ������ ��������, ���� �����
                if (current->leftChild != nullptr) {
                    current = current->leftChild;
                    continue;
                }
                // ���� ������ ���� ���, �� ����� ����� ��� ������ ��������
                newNode = new Node(newdata, current);
                current->leftChild = newNode;
            }
            else
            {
                // ���� ������� ������ ��������, ���� ������
                if (current->rightChild != nullptr) 
                {
                    current = current->rightChild;
                    continue;
                }
                // ���� ������� ���� ���, �� ����� ����� ��� ������ ��������
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
        return; // ������ ������ ����� ��� � ������
    // ����� ����� ����
    if (isLeaf(foundForDel)) { // ���� ��� ����, ������ ������ ���
        delLeaf(foundForDel);
    }
    else {
        // ���� �� ����, �� �������� �������
        if (foundForDel->leftChild == nullptr || foundForDel->rightChild == nullptr) {
            // ������, ����� � ���� ������ ���� ��������
            delNodeWithOneChild(foundForDel);
        }
        else {
            // ���� ������ ������� ������ ���������
            Node* mostright = foundForDel->leftChild;
            while (mostright->rightChild != nullptr)
                mostright = mostright->rightChild;

            // �������� ������ �� ������� ������ ������ � ��������� ����  
            foundForDel->data = mostright->data;

            // ������� ������ ������� (�� ����� ��������� ������ ����� ����)
            if (mostright->leftChild != nullptr)
                delNodeWithOneChild(mostright);
            else
                delLeaf(mostright);
        }
    }
}

// ��������� ��� �������� ���� child ������ ���������
// ���� newChild ������ child (��� ����������� �������� ����)
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

// ������� ���� � ����� �������� ����� �� ������
void BinaryTree::delNodeWithOneChild(Node* delNode) {
    if (delNode->leftChild != nullptr) {
        // ���� ����� ����� ����
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
        // ���� ������ ����
        if (isRoot(delNode)) {
            root = delNode->rightChild;
        }
        else {
            setNewChild(delNode, delNode->rightChild);
        }
        delNode->rightChild->parent = delNode->parent;
        delNode->rightChild = nullptr;
    }
    // ������� ����
    delete delNode;
}
// ������� ���� �� ������
void BinaryTree::delLeaf(Node* leaf) {
    if (isRoot(leaf)) { // ������, ����� � ������ ����� ���� �������� ����
        // �������� ������
        root = nullptr;
    }
    else {
        // �������� ��������� �� ��������� ���� � ��������
        setNewChild(leaf);
    }
    // ������� �������� ����
    delete leaf;
}
