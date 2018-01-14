#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

    int T;
    int N;
    int temp;
    vector<int> v;
    cin>>T;
    while(T-->0){
        v.clear();
        cin>>N;
        for(int i=0;i<N;++i){
            cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end(),[](int a,int b){return a<b;});
        for(auto i:v){
            cout<<i<<endl;
        }
    }

    return 0;
}
