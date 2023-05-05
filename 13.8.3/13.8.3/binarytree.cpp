#include "binarytree.h"
//
BinaryTree::Node::Node(int d, Node* p) :
    data(d), parent(p) {
    leftChild = nullptr;
    rightChild = nullptr;
}
//
BinaryTree::Node::~Node() {
    // ������ �� ����� ������
    if (rightChild != nullptr)
        delete rightChild;
    if (leftChild != nullptr)
        delete leftChild;
}
//
BinaryTree::BinaryTree() {
    root = nullptr;
}
//
BinaryTree::~BinaryTree() {
    if (root != nullptr)
    {
        delete root;
    }
}
void BinaryTree::addInt(int newdata) {
    if (root == nullptr) {
        // ���� ������ ������, �� ����� ������� ������ ������
        root = new Node(newdata);
    }
    else {
        Node* current = root; // �������� � �����
        Node* newNode = nullptr;
        while (newNode == nullptr) {
            if (current->data >= newdata) {
                // ���� ������� ������ ��������, ���� �����
                if (current->leftChild != nullptr) {
                    current = current->leftChild;
                    continue;
                }
                // ���� ������ ���� ���, �� ����� ����� ��� ������ ��������
                newNode = new Node(newdata, current);
                current->leftChild = newNode;
            }
            else {
                // ���� ������� ������ ��������, ���� ������
                if (current->rightChild != nullptr) {
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
//