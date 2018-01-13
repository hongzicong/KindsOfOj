#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int n;
    int temp;
    int count=0;
    vector<int> v;
    vector<int> max;
    vector<int> min;
    while(cin>>n){
        count=0;
        v.clear();
        max.clear();
        min.clear();
        for(int i=0;i<n;++i){
            cin>>temp;
            v.push_back(temp);
        }
        max.push_back(v[0]);
        temp=max[0];
        for(int i=1;i<n;++i){
            if(v[i]>temp){
                temp=v[i];
            }
            max.push_back(temp);
        }
        min.push_back(v[n-1]);
        temp=min[0];
        for(int i=n-2;i>=0;--i){
            if(v[i]<temp){
                temp=v[i];
            }
            min.push_back(temp);
        }
        for(int i=0;i<n;++i){
            if(v[i]>=max[i]&&v[i]<=min[n-1-i]){
                count++;
            }
        }
        cout<<count<<endl;
    }

    return 0;
}

