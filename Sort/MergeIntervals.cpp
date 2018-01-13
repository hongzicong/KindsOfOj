#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    //应该要用static才行，否则会出错
    static bool cmp(Interval& a,Interval& b){
        return a.start<b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        //一定要判断传进来的是不是空的intervals
        if(intervals.size()==0){
            return result;
        }
        sort(intervals.begin(),intervals.end(),[](Interval &a,Interval &b){return a.start<b.start;});
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i){
            if(intervals[i].start>result.back().end){
                result.push_back(intervals[i]);
            }
            else{
                result.back().end=max(intervals[i].end,result.back().end);
            }
        }
        return result;
    }
};

int main(void){

    Solution s;
    vector<Interval> v{*(new Interval(1,3)),*(new Interval(2,6)),*(new Interval(8,10)),*(new Interval(15,18))};
    vector<Interval> v1=s.merge(v);
    for(auto i:v1){
        cout<<"["<<i.start<<","<<i.end<<"]"<<endl;
    }
    return 0;
}

