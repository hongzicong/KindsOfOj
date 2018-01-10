#include <iostream>

using namespace std;

int binSearch(const int s[],const int size,const int target){
    int i=0,j=size-1,middle;
    while(i<=j){
        middle=(i+j)/2;
        if(s[middle]==target){
            while(middle+1<size&&s[middle+1]==target){
                middle++;
            }
            return middle;
        }
        else if(s[middle]<target){
            i=middle+1;
        }
        else{
            j=middle-1;
        }
    }
    return -1;
}

int main(void){
    int v[5]={1,2,3,4,4};
    cout<<binSearch(v,5,4)<<endl;
    return 0;
}
