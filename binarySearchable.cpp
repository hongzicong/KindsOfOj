#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int n;
    int temp;
    vector<int> v;
    while(cin>>n){
        v.clear();
        for(int i=0;i<n;++i){
            cin>>temp;
            v.push_back(temp);
        }
        bool can=true;
        int count=0;
        for(int i=0;i<n;++i){
            can=true;
            for(int j=0;j<i;++j){
                if(v[j]>v[i]){
                    can=false;
                    break;
                }
            }
            for(int j=i+1;j<n;++j){
                if(v[j]<v[i]){
                    can=false;
                    break;
                }
            }
            if(can){
                count++;
            }
        }
        cout<<count<<endl;
    }

    return 0;
}

