/**
* Leetcode Problem - https://leetcode.com/problems/find-target-indices-after-sorting-array/
* Author - Shubham Nagaria
* Date - 22nd Dec 2021
**/
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int c=0,s=0;
        for(auto & i : nums)
        {
            c+=(i<target);
            s+=(i==target);
        }
        vector<int>res;
         while(s--)
        res.push_back(c++);
    return res;
    }
};
