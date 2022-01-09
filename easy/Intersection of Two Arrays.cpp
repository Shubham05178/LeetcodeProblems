/**
* Leetcode Problem - https://leetcode.com/problems/intersection-of-two-arrays/
* Author - Shubham Nagaria
* Date - 9th Jan 2022
**/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s(nums1.begin(),nums1.end());
        vector<int>res;
        for(int &i : nums2)
            if(s.erase(i))
                res.push_back(i);
        return res;
    }
};


