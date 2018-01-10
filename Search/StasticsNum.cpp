#include <iostream>
#include <map>

using namespace std;

int main(void){

    int n,temp;
    map<long,int> m;
    bool contin=true;
    while(cin>>n){
        if(contin==true){
            contin=false;
        }
        else{
            cout<<endl;
        }
        m.clear();
        while(n-->0){
            cin>>temp;
            if(m.find(temp)==m.end()){
                m.insert(make_pair(temp,1));
            }
            else{
                m.find(temp)->second++;
            }
        }
        for(auto p:m){
            cout<<p.first<<" "<<p.second<<endl;
        }
    }


    return 0;
}