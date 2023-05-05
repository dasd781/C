#include<iostream>
#include"binarytree.h"
#include<vector>
using namespace std;
// симметричный обход
void BinaryTree::symmetricWalk(int output_array[]) {

    Node* current = root;
    std::vector<int> output;
    printInorder(current, output);
    for (int i = 0; i < SIZE; i++)
    {
        output_array[i] = output[i];
        cout << output_array[i] << "  ";
    }


}
void BinaryTree::printInorder(Node* node, std::vector <int>& output)
{


    if (node == nullptr)
        return;


    printInorder(node->leftChild, output);


    output.push_back(node->data);



    printInorder(node->rightChild, output);

}
