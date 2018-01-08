#include <iostream>
#include <stack>

using namespace std;

int main(void){

    int T;
    string s;
    double a,b;
    stack<double> mStack;
    cin>>T;
    cin.get();
    while(T-->0){
        getline(cin,s);
        for(int i=0;i<s.length();++i){
            if(s[i]<='z'&&s[i]>='a'){
                mStack.push(s[i]-'a'+1);
            }
            if(s[i]=='+'){
                a=mStack.top();
                mStack.pop();
                b=mStack.top();
                mStack.pop();
                mStack.push(a+b);
            }
            else if(s[i]=='*'){
                a=mStack.top();
                mStack.pop();
                b=mStack.top();
                mStack.pop();
                mStack.push(a*b);
            }
            else if(s[i]=='-'){
                a=mStack.top();
                mStack.pop();
                b=mStack.top();
                mStack.pop();
                mStack.push(b-a);
            }
            else if(s[i]=='/'){
                a=mStack.top();
                mStack.pop();
                b=mStack.top();
                mStack.pop();
                mStack.push(b/a);
            }
        }
        printf("%0.2f\n",mStack.top());
        mStack.pop();
    }

    return 0;
}

