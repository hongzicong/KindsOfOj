#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;
    int height;
    Node():value(0),left(nullptr),right(nullptr),height(0){}
};

class AVLTree{
private:
    Node *root;
    Node *singleRotateWithLeft(Node *k2);
    Node *singleRotateWithRight(Node *k2);
    Node *doubleRotateWithLeft(Node *k2);
    Node *doubleRotateWithRight(Node *k2);
    Node *insert(int value,Node *node);
    int getHeight(Node *node);
    int max(int a,int b);
    void printPreorder(Node *node);
public:
    AVLTree():root(nullptr){}
    void insert(int value);
    void printTreePreorder();
};

int main(void){
    int count;
    cin>>count;
    while(count-->0){
        int n;
        int temp;
        cin>>n;

        AVLTree mTree;

        for(int i=0;i<n;++i){
            cin>>temp;
            mTree.insert(temp);
        }
        mTree.printTreePreorder();
        cout<<endl;
    }

    return 0;
}

void AVLTree::printPreorder(Node *node){
    if(node!=nullptr){
        cout<<node->value<<" ";
        printPreorder(node->left);
        printPreorder(node->right);
    }
}

void AVLTree::printTreePreorder(){
    printPreorder(root);
}

void AVLTree::insert(int value){
    root=insert(value,root);
}

Node *AVLTree::insert(int value,Node *node){
    if(node==nullptr){
        Node *node=new Node();
        node->value=value;
        return node;
    }
    else if(value<node->value){
        node->left=insert(value,node->left);
        if(getHeight(node->left)==getHeight(node->right)+2){
            if(value<node->left->value){
                node=singleRotateWithLeft(node);
            }
            else{
                node=doubleRotateWithLeft(node);
            }
        }
    }
    else if(value>node->value){
        node->right=insert(value,node->right);
        if(getHeight(node->right)==getHeight(node->left)+2){
            if(value>node->right->value){
                node=singleRotateWithRight(node);
            }
            else{
                node=doubleRotateWithRight(node);
            }
        }
    }
    node->height=max(getHeight(node->left),getHeight(node->right))+1;
    return node;
}

int AVLTree::max(int a,int b){
    return (a>b)?a:b;
}

int AVLTree::getHeight(Node *node){
    if(node==nullptr){
        return -1;
    }
    return node->height;
}

Node *AVLTree::singleRotateWithLeft(Node *k2){
    Node *k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(getHeight(k2->left),getHeight(k2->right))+1;
    k1->height=max(k2->height,getHeight(k1->left))+1;
    return k1;
}

Node *AVLTree::singleRotateWithRight(Node *k2){
    Node *k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    k2->height=max(getHeight(k2->left),getHeight(k2->right))+1;
    k1->height=max(k2->height,getHeight(k1->right))+1;
    return k1;
}

Node *AVLTree::doubleRotateWithLeft(Node *k2){
    k2->left=singleRotateWithRight(k2->left);
    return singleRotateWithLeft(k2);
}

Node *AVLTree::doubleRotateWithRight(Node *k2){
    k2->right=singleRotateWithLeft(k2->right);
    return singleRotateWithRight(k2);
}