#include <iostream>

using namespace std;


void process(char *inorder,char *pre,int length);

int main(void){

    string line;
    char pre[26];
    char inorder[26];
    getline(cin,line);
    for(int i=0;i<line.size();++i){
        pre[i]=line[i];
    }
    getline(cin,line);
    for(int i=0;i<line.size();++i){
        inorder[i]=line[i];
    }
    process(inorder,pre,line.size());
    return 0;
}


void process(char *inorder,char *pre,int length){
    if(length==0){
        return;
    }
    int i=0;
    for(;i<length;++i){
        if(inorder[i]==*pre){
            break;
        }
    }
    //先处理左子树
    process(inorder,pre+1,i);
    //再处理右子树
    process(inorder+i+1,pre+i+1,length-i-1);
    //每次最后才打印父节点
    cout<<*pre;
}
