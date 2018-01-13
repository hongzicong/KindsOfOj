#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> intersection_1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> s1(nums1.begin(),nums1.end());
        for(auto i:nums2){
            if(s1.erase(i)){
                result.push_back(i);
            }
        }
        return result;
    }
    vector<int> intersection_2(vector<int> &nums1,vector<int>& nums2){
        vector<int> result;
        unordered_map<int,int> m;
        for(auto i:nums1){
            m[i]++;
        }
        for(auto i:nums2){
            if(--m[i]>=0){
                result.push_back(i);
            }
        }
        return result;
    }
};

int main(void){

    Solution s;
    vector<int> v1{1,2,2,1};
    vector<int> v2{2,2};
    vector<int> result=s.intersection_2(v1,v2);
    for(auto i:result){
        cout<<i<<endl;
    }

    return 0;
}


