#include <iostream>
#include <cstdlib>

using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
};

void printCurrentLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

void printLevelOrder(node* root) {
    int h = height(root), i;
    for(i = 0; i <= h; i++) {
        printCurrentLevel(root, i);
    }
}

void printCurrentLevel(node* root, int level) {
    if(root == NULL) return;
    if(level == 1) {
        cout << root->data << " "; 
    } else if(level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(node* node) {
    if(node == NULL) {
        return 0;
    } else {
        int l_height = height(node->left);
        int r_height = height(node->right);

        if(l_height > r_height) {
            return (l_height + 1);
        } else {
            return (r_height + 1);
        }
    }
}

node* newNode(int data) {
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

int main() {
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "Level Order traversal of binary tree is" << endl;
    printLevelOrder(root);

    return 0;
}