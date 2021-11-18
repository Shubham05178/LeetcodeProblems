/**
* Leetocde problem - https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
* Author - Shubham Nagaria
* Date - 18th Nov 2021
**/ 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size()+1;
        vector<int>v(n,0),res;
        for(auto ch:nums)
            v[ch]++;
        for(int i =1; i <n; i++){
            if(v[i]==0) res.push_back(i);
        }
        return res;
    }
};
