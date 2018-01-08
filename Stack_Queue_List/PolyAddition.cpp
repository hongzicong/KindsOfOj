//我真是个智障，这种情况明明用map就好了，玛德智障写了一个下午
#include <iostream>
#include <map>

using namespace std;

int main(void){

    map<int,int> p;

    int m,length;
    cin>>m;
    int temp1,temp2;
    while(m-->0){
        p.clear();
        cin>>length;
        for(int i=0;i<length;++i){
            cin>>temp1>>temp2;
            p.insert(make_pair(temp2,temp1));
        }
        cin>>length;
        for(int i=0;i<length;++i){
            cin>>temp1>>temp2;
            if(p.find(temp2)!=p.end()){
                p.find(temp2)->second+=temp1;
                if(p.find(temp2)->second==0){
                    p.erase(p.find(temp2));
                }
            }
            else{
                p.insert(make_pair(temp2,temp1));
            }
        }
        cout<<p.size()<<endl;
        for(auto a=p.rbegin();a!=p.rend();++a){
            cout<<a->second<<" "<<a->first<<endl;
        }
    }

    return 0;
}

