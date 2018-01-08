#include <iostream>

using namespace std;

int main(void){

    int tempRow[100];
    int result[100];

    int N;
    int temp;
    scanf("%d",&N);
    scanf("%d",&temp);
    tempRow[0]=temp;
    result[0]=tempRow[0];
    for(int i=1;i<N;++i){
        for(int j=0;j<i+1;++j){
            scanf("%d",&temp);
            tempRow[j]=temp;
        }
        result[i]=result[i-1]+tempRow[i];
        for(int j=i-1;j>0;--j){
            result[j]=max(result[j-1],result[j])+tempRow[j];
        }
        result[0]=result[0]+tempRow[0];
    }
    int max=-1;
    for(int i=0;i<N;++i){
        if(result[i]>max){
            max=result[i];
        }
    }
    printf("%d\n",max);
    return 0;
}


