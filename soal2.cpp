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

void printPostOrder(node* node) {
    if(node == NULL) return;

    printPostOrder(node->left);

    printPostOrder(node->right);

    cout << node->data << " ";
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

int main() {
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->left = newNode(12);
    root->right->right->left = newNode(13);
    
    cout << "Preorder traversal of binary tree is" << endl;
    printPreOrder(root);

    cout << "\n\nInorder traversal of binary tree is" << endl;
    printInOrder(root);

    cout << "\n\nPreorder traversal of binary tree is" << endl;
    printPostOrder(root);

    return 0;
}