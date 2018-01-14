#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct BinaryNode{
    int elem;
    BinaryNode *left;
    BinaryNode * right;
    BinaryNode(int d, BinaryNode *l=NULL, BinaryNode *r=NULL):elem(d),left(l),right(r){};
};

void levelTraversal(BinaryNode *root){
    queue<BinaryNode *> q;
    BinaryNode *temp;
    if(root!= nullptr){
        q.push(root);
        while(!q.empty()){
            temp=q.front();
            q.pop();
            if(temp->left!= nullptr){
                q.push(temp->left);
            }
            if(temp->right!= nullptr){
                q.push(temp->right);
            }
            cout<<temp->elem<<" ";
        }
    }
}

void preOrderTraverse(BinaryNode *root){
    if(root!=nullptr){
        stack<BinaryNode *> s;
        while(root||!s.empty()){
            if(root){
                s.push(root);
                cout<<root->elem<<" ";
                root=root->left;
            } else{
                root=s.top();
                s.pop();
                root=root->right;
            }
        }
    }
}

void InOrderTraverse(BinaryNode *root){
    if(root!= nullptr){
        stack<BinaryNode *>s;
        while(root||!s.empty()){
            if(root){
                s.push(root);
                root=root->left;
            } else{
                root=s.top();
                s.pop();
                cout<<root->elem<<" ";
                root=root->right;
            }
        }
    }
}

void PostOrderTraverse(BinaryNode *root){
    if(root!= nullptr){
        stack<BinaryNode *>s;
        BinaryNode *r= nullptr;
        while(root||!s.empty()){
            if(root){
                s.push(root);
                root=root->left;
            } else{
                root=s.top();
                if(root->right&&root->right!=r){
                    root=root->right;
                    s.push(root);
                    root=root->left;
                } else{
                    root=s.top();
                    s.pop();
                    cout<<root->elem<<" ";
                    r=root;
                    root= nullptr;
                }
            }
        }
    }
}

int main(void){

    BinaryNode a(1),b(2),c(3,&a,&b);
    levelTraversal(&c);
    return 0;
}
