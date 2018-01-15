#include <iostream>
#include <climits>

using namespace std;

int matrix[500][500];

bool known[500];

int main(void){

    int T,temp,count=0;
    int maxLength;
    int N;
    cin>>T;
    while(T-->0){
        count=0;
        maxLength=0;
        cin>>N;
        for(int i=0;i<N;++i){
            known[i]=false;
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cin>>matrix[i][j];
            }
        }
        known[0]=true;
        count++;
        while(count!=N){
            int min=INT_MAX;
            int min_i=-1;
            int min_j=-1;
            for(int i=0;i<N;++i){
                if(known[i]==true){
                    for(int j=0;j<N;++j){
                        if(matrix[i][j]!=0&&known[j]==false){
                            if(matrix[i][j]<min){
                                min=matrix[i][j];
                                min_i=i;
                                min_j=j;
                            }
                        }
                    }
                }
            }
            if(min_j!=-1){
                known[min_j]=true;
                if(matrix[min_i][min_j]>maxLength){
                    maxLength=matrix[min_i][min_j];
                }
                count++;
            }
        }
        cout<<maxLength<<endl;
        if(T!=0){
            cout<<endl;
        }
    }
    return 0;
}
