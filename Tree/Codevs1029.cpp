#include <iostream>

using namespace std;

int main(void){

    string pre,post;
    cin>>pre>>post;
    int result=1;
    for(int i=0;i<pre.size()-1;++i){
        for(int j=post.size()-1;j>0;--j){
            if(pre[i]==post[j]&&pre[i+1]==post[j-1]){
                result<<=1;
            }
        }
    }
    cout<<result<<endl;
    return 0;
}