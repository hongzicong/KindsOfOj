#include <iostream>
#include <map>

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

void swapArr(int *a,int *b){
    int temp;
    for(int i=0;i<11;++i){
        temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}

int main(void){

    int T;
    cin>>T;
    int mArray[100][11];
    while(T-->0){
        int Q;
        int temp;
        cin>>N>>M;

        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                cin>>temp;
                mArray[i][j]=temp;
            }
        }

        for(int j=0;j<N;++j){
            mArray[j][10]=j;
        }

        cin>>Q;
        for(int i=0;i<Q;++i){
            mMap.clear();
            for(int j=0;j<M;++j){
                cin>>temp;
                mMap.insert(make_pair(temp,j));
            }

            //bubble sort
            for(int j=0;j<N-1;++j){
                for(int k=0;k<N-1-j;++k){
                    if(cmp(mArray[k],mArray[k+1])){
                        swapArr(mArray[k],mArray[k+1]);
                    }
                }
            }

            for(int j=0;j<N;++j){
                cout<<mArray[j][10]<<((j==N-1)?"":" ");
            }
            cout<<endl;
        }

    }

    return 0;
}

