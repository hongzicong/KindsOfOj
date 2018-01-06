// Problem#: 21555
// Submission#: 5250630
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <set>

int main(void){

    int C,N;
    int temp;
    std::set<int> s;
    std::vector<int> v;
    std::vector<int> result;
    while(std::cin>>C>>N){
        s.clear();
        v.clear();
        result.clear();
        for(int i=0;i<N;++i){
            std::cin>>temp;
            v.push_back(temp);
        }
        for(int i=v.size()-1;i>=0;--i){
            if(s.find(v[i])==s.end()){
                result.push_back(v[i]);
                s.insert(v[i]);
            }
        }
        std::cout<<result.size()<<std::endl;
        for(int i=result.size()-1;result.size()!=N&&i>=0;--i){
            std::cout<<result[i]<<((i==0)?"":" ");
        }
        std::cout<<std::endl;
    }

    return 0;
}                                 