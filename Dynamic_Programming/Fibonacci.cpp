#include <iostream>

using namespace std;

//递归的方法
int Fib(int N){
    if(N<=1){
        return 1;
    }
    else{
        return Fib(N-1)+Fib(N-2);
    }
}

//非递归的方法
int Fib_2(int N){
    int result=0;
    if(N<=1){
        return 1;
    }
    int pre=1,doublePre=1;
    for(int i=2;i<=N;++i){
        result=pre+doublePre;
        doublePre=pre;
        pre=result;
    }
    return result;
}

int main(void){

    cout<<Fib(10)<<endl;
    cout<<Fib_2(10)<<endl;


    return 0;
}
