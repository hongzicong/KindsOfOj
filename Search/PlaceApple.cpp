#include <stdio.h>

int count;

void dfs(int pre,int remain,int nowN,int countN){
    if(nowN==countN&&remain>=pre){
        count++;
        //当满足这个情况以后，就不需要再继续后面的了，因为已经放到最后一个盒子了
        return;
    }
    for(int i=pre;i<=remain-i;++i){
        dfs(i,remain-i,nowN+1,countN);
    }
}

int main(void){

    int t;
    int M,N;
    scanf("%d",&t);
    while(t-->0){
        count=0;
        scanf("%d %d",&M,&N);
        dfs(0,M,1,N);
        printf("%d\n",count);
    }


    return 0;
}
