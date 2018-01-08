#include <iostream>
#include <deque>

using namespace std;

int main(void){

    int t;
    int n,pos,temp;
    bool isPop=true;
    deque<int> d;
    cin>>t;
    while(t-->0){
        d.clear();
        cin>>n;
        cin>>pos;
        for(int i=0;i<n;++i){
            cin>>temp;
            d.push_back(temp);
        }
        int count=0;
        while(pos>=0){
            temp=d.front();
            d.pop_front();
            if(d.empty()){
                count++;
                break;
            }
            isPop=true;
            for(auto i:d){
                if(temp<i){
                    d.push_back(temp);
                    if(pos==0){
                        pos=d.size()-1;
                    }
                    else{
                        pos--;
                    }
                    isPop=false;
                    break;
                }
            }
            if(isPop){
                pos--;
                count++;
            }
        }
        cout<<count<<endl;
    }

    return 0;
}

