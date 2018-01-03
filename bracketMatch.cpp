#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){

    int count;
    cin>>count;
    while(count-->0){
        bool isMatch=true;
        string temp;
        stack<char> s;
        cin>>temp;
        for(char ch:temp){
            switch(ch){
                case '{':
                case '[':
                case '(':
                    s.push(ch);
                    break;
                case '}':
                    if(s.empty()||s.top()!='{'){
                        isMatch=false;
                    }
                    else{
                        s.pop();
                    }
                    break;
                case ']':
                    if(s.empty()||s.top()!='['){
                        isMatch=false;
                    }
                    else{
                        s.pop();
                    }
                    break;
                case ')':
                    if(s.empty()||s.top()!='('){
                        isMatch=false;
                    }
                    else{
                        s.pop();
                    }
                    break;
            }
            if(isMatch==false){
                break;
            }
        }
        cout<<((isMatch&&s.empty())?"Yes":"No")<<endl;
    }


    return 0;
}                                 