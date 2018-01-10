#include <iostream>
#include <cctype>

using namespace std;

int main(void){

    string s;
    string result;
    char pre;
    int temp;
    cin>>s;
    while(s!="XXX"){
        result.clear();
        temp=0;
        for(int i=0;i<s.size();++i){
            if(isalpha(s[i])){
                if(temp!=0){
                    while(--temp>0){
                        result.push_back(pre);
                    }
                }
                result.push_back(s[i]);
                pre=s[i];
            }
            else{
                temp=temp*10+(s[i]-'0');
            }
        }
        while(--temp>0){
            result.push_back(pre);
        }
        cout<<result<<endl;
        cin>>s;
    }

    return 0;

}

