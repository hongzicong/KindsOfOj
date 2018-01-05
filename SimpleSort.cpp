#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N,M;
map<int,int> mMap;

bool cmp(int *a,int *b){
    int i;
    for(auto pair:mMap){
        i=pair.second;
        if(a[i]<b[i]){
            return false;
        }
        else if(a[i]>b[i]){
            return true;
        }
    }
    return false;
}

int main(void){

    int T;
    cin>>T;
    while(T-->0){
        int array[100][11];
        int Q;
        int temp;
        cin>>N>>M;
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                cin>>temp;
                array[i][j]=temp;
            }
        }
        int resultOrder[10][10];
        cin>>Q;
        for(int i=0;i<Q;++i){
            mMap.clear();
            for(int j=0;j<M;++j){
                cin>>temp;
                mMap.insert(make_pair(temp,j));
            }
            for(int j=0;j<100;++j){
                array[j][10]=j;
            }
            for(int j=0;j<N-1;++j){
                for(int k=j+1;k<N;++k){
                    if(cmp(array[j],array[k])){
                        temp=array[j][10];
                        array[j][10]=array[k][10];
                        array[k][10]=temp;
                    }
                }
            }
            for(int j=0;j<N;++j){
                resultOrder[i][j]=array[j][10];
            }
        }
        for(int i=0;i<Q;++i){
            for(int j=0;j<N;++j){
                cout<<resultOrder[i][j]<<((j==N-1)?"":" ");
            }
            cout<<endl;
        }
    }

    return 0;
}

