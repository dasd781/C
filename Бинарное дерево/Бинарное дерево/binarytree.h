#pragma once

#ifndef __BYNARYTREE_H_
#define __BYNARYTREE_H_

#include "test.h"

class BinaryTree {
public:
    struct Node { // ��������� ����
        Node(int d, Node* p = nullptr);
        ~Node();
        Node* parent; // ������������ ����

        Node* leftChild; // ����� ����
        Node* rightChild; // ������ ����

        int data; // ������ - ����� �����
    };

    BinaryTree();
    ~BinaryTree();

    void addInt(int newdata);

    Node* findNodeByData(int finddata);
    void delInt(int deldata);

    friend Table print(BinaryTree& tree);

private:
    void setNewChild(Node* child, Node* newChild = nullptr);
    void delNodeWithOneChild(Node* delNode);
    void delLeaf(Node* leaf);
    // �������� �������� �� ���� ������        
    bool isLeaf(Node* check);
    // ��������, ������� �� ���� ��������
    bool isRoot(Node* check);
    Node* root; // �������� ����
};
#endif
