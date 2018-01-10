#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void){

    int n,temp;
    int count1,count2;
    set<int> v;
    set<int> s;
    vector<int> result;
    cin>>n;
    while(n-->0){
        v.clear();
        s.clear();
        result.clear();
        cin>>count1;
        for(int i=0;i<count1;++i){
            cin>>temp;
            v.insert(temp);
        }
        cin>>count2;
        for(int i=0;i<count2;++i){
            cin>>temp;
            s.insert(temp);
        }
        for(auto i:v){
            if(s.find(i)==s.end()){
                result.push_back(i);
            }
        }
        for(int i=0;i<result.size();++i){
            cout<<result[i];
            if(i!=result.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
