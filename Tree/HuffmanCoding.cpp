#include <iostream>
#include <map>
#include <deque>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    Node():left(nullptr),right(nullptr),num(0),c('0'){}
    int num;
    char c;
    string s;
    Node *left,*right;
};

void createCode(string &s,Node *root){
    if(root!= nullptr){
        if(root->c!='0'){
            root->s=s;
            return;
        }
        else{
            string s1=s+"1",s2=s+"0";
            createCode(s1,root->right);
            createCode(s2,root->left);
        }
    }
}

bool cmp(Node *a,Node *b){
    return a->num>=b->num;
}

void printCode(Node *root){
    vector<Node *> v;
    deque<Node *> d;
    d.push_back(root);
    while(!d.empty()){
        Node *temp=d.front();
        d.pop_front();
        if(temp->c!='0'){
            v.push_back(temp);
        }
        if(temp->right!= nullptr)
            d.push_back(temp->right);
        if(temp->left!=nullptr)
            d.push_back(temp->left);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto a:v){
        cout<<a->c<<" "<<a->num<<" "<<a->s<<endl;
    }
}

int main(void){

    int n;
    map<char,int> m;
    deque<Node *> v;
    char ch;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>ch;
        if(m.find(ch)==m.end()){
            m.insert(make_pair(ch,1));
        }
        else{
            (m.find(ch)->second)++;
        }
    }
    Node *temp;
    for(auto p:m){
        temp=new Node;
        temp->num=p.second;
        temp->c=p.first;
        v.push_back(temp);
    }
    int min_i,sec_min_i;
    int min,sec_min;
    int all=v.size();
    while(all!=1){
        min=INT_MAX;
        for(int i=0;i<v.size();++i){
            if(v[i]!= nullptr&&min>v[i]->num){
                min=v[i]->num;
                min_i=i;
            }
        }
        sec_min=INT_MAX;
        for(int i=0;i<v.size();++i){
            if(v[i]!= nullptr&&i!=min_i&&sec_min>v[i]->num){
                sec_min=v[i]->num;
                sec_min_i=i;
            }
        }
        temp=new Node;
        temp->left=v[min_i];
        temp->right=v[sec_min_i];
        temp->num=temp->left->num+temp->right->num;
        v.push_back(temp);
        all--;
        v[min_i]= nullptr;
        v[sec_min_i]=nullptr;
    }
    for(int i=0;i<v.size();++i){
        if(v[i]!=nullptr){
            string s;
            if(v[i]->c!='0'){
                cout<<v[i]->c<<" "<<v[i]->num<<" "<<1;
                return 0;
            }
            createCode(s,v[i]);
            printCode(v[i]);
            break;
        }
    }

    return 0;
}

