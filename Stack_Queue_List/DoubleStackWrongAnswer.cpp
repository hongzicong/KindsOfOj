#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {

    int caseCount=0;
    int temp;
    cin>>caseCount;
    vector<int> inNum(caseCount);
    vector<char> oper;
    stack<int> firstStack;
    stack<int> secondStack;
    for(int i=0; i<caseCount; ++i) {
        cin>>temp;
        inNum[i]=temp;
    }
    int j=0;
    int i=1;
    while(i<=caseCount) {
        if(!firstStack.empty()&&firstStack.top()==i) {
            firstStack.pop();
            oper.push_back('b');
            ++i;
        } else if(!secondStack.empty()&&secondStack.top()==i) {
            secondStack.pop();
            oper.push_back('d');
            ++i;
        } else {
            if(firstStack.empty()) {
                firstStack.push(inNum[j]);
                oper.push_back('a');
                ++j;
            } else if(inNum[j]<firstStack.top()) {
                firstStack.push(inNum[j]);
                oper.push_back('a');
                ++j;
            } else if(secondStack.empty()) {
                secondStack.push(inNum[j]);
                oper.push_back('c');
                ++j;
            } else if(inNum[j]<secondStack.top()) {
                secondStack.push(inNum[j]);
                oper.push_back('c');
                ++j;
            } else {
                break;
            }
        }
    }

    if(i!=caseCount+1) {
        cout<<0<<endl;
    } else {
        auto curr=oper.begin();
        for(; (curr+1)!=oper.end(); ++curr) {
            cout<<*curr<<" ";
        }
        cout<<*curr;
    }

    return 0;
}

