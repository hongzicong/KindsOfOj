#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //这里的string不用引用的话，就会复制传进去的参数，这就不用自己考虑生成string什么的了
    static void DFS(vector<string> &v,TreeNode *root,string s){
        if(root->left == nullptr&&root->right== nullptr){
            v.push_back(s);
            return;
        }
        if(root->left!= nullptr){
            //数字变string可以直接用to_string的方法
            DFS(v,root->left,s+"->"+to_string(root->left->val));
        }
        if(root->right!= nullptr){
            DFS(v,root->right,s+"->"+to_string(root->right->val));
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(!root){
            return v;
        }
        DFS(v,root,to_string(root->val));
        return v;
    }
};

int main(void){

    Solution s;
    TreeNode *root=new TreeNode(1);
    TreeNode *left=new TreeNode(2);
    TreeNode *right=new TreeNode(3);
    root->left=left;
    root->right=right;
    vector<string> v=s.binaryTreePaths(root);
    cout<<v[0]<<endl;
    cout<<v[1];
    return 0;
}
