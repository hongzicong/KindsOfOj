#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> v1;
vector<char> v2;

int getNumFromVec(vector<char> &v){
    int result=0;
    //todo
    return result;
}

int cmp(string &a,string &b){
    bool preIsDigital=false;
    int i=0;
    v1.clear();
    for(;i<min(a.size(),b.size());++i){
        if(tolower(a[i])==tolower(b[i])){
            if(!isdigit(a[i])&&tolower(a[i])!='+'&&tolower(a[i])!='-'){
                preIsDigital=false;
                if(!v1.empty()){
                    //todo process number
                }
            }
            else if(tolower(a[i])=='+'||tolower(a[i])=='-'){
                if(preIsDigital==true){
                    preIsDigital=false;
                }
                else{
                    if(v1.empty()){
                        v1.push_back(a[i]);
                        v2.push_back(a[i]);
                    }
                    else{
                        //todo process number
                    }
                }
            }
            else{
                v1.push_back(a[i]);
                v2.push_back(a[i]);
                preIsDigital=true;
            }
            continue;
        }
        else if(!isdigit(a[i])&&!isdigit(b[i])&&){
            return (tolower(a[i])>tolower(b[i]))?1:-1;
        }
        else
    }

    if(i==a.size()&&i==b.size()) {
        return 0;
    }
    else if(i==a.size()){
        return -1;
    }
    else{
        return 1;
    }

}

int main(void){

    int N;
    string a,b;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a;
        cin>>b;
        cout<<i+1<<" "<<cmp(a,b)<<endl;
    }

    return 0;
}
