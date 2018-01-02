#include <iostream>

struct Node{
    Node():data(0),left(nullptr),right(nullptr),height(0){}
    int data;
    int height;
    Node *left;
    Node *right;
};

class AVLTree{
public:
    AVLTree():root(nullptr);
    void insert(const int new_data);
    void remove(const int old_data);
    Node *find(int data);
    int getHeight();
private:
    Node *root;
    void insert(Node *node,int value);
    Node *singleRotateLeft(Node* k2);
    Node *singleRotateRight(Node* k2);
    Node *doubleRotateRL(Node* tree);
    Node *doubleRotateLR(Node* tree);
    int max(int a,int b);
};

int main(){



    return 0;
}

int AVLTree::max(int a,int b){
    return (a>b)?a:b;
};

int AVLTree::getHeight() {
    if(root== nullptr){
        return -1;
    }
    return root->height;
}

Node *AVLTree::singleRotateLeft(Node *k2){
    Node *k1;
    k1=k2->left;
    k2->left=k1->left;
    k1->right=k2;

    return k1;
}

Node *AVLTree::singleRotateRight(Node *k2){
    Node *k1;
    k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;

    return k1;
}