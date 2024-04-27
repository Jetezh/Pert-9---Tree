#include <iostream>
#include <cstdlib>

using namespace std;

class node {
    public:
        int data;
        node* left; 
        node* right;
};

node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printInOrder(node* node){
    if(node == NULL) return;

    printInOrder(node->left);

    cout << node->data << " ";

    printInOrder(node->right);
}

void printPreOrder(node* node) {
    if(node == NULL) return;

    cout << node->data << " ";

    printPreOrder(node->left);

    printPreOrder(node->right);
}

void printPostOrder(node* node) {
    if(node == NULL) return;

    printPostOrder(node->left);

    printPostOrder(node->right);

    cout << node->data << " ";
}

int main() {
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    cout << "Preorder traversal of binary tree is" << endl;
    printPreOrder(root);

    cout << "\n\nInorder traversal of binary tree is" << endl;
    printInOrder(root);

    cout << "\n\nPostorder traversal of binary tree is" << endl;
    printPostOrder(root);

    return 0;
}