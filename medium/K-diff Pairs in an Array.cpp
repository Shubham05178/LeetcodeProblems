/**
* Leetcode Problem - https://leetcode.com/problems/k-diff-pairs-in-an-array/
* Author - Shubham Nagaria
* Date - 9th Feb 2022
**/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count =0;
        for(int i : nums)
                mp[i]++;
        for(auto p : mp){
            if(k==0){
                if(p.second > 1) 
                    count++;
            }
            else if (mp.find(p.first+k) != mp.end()) count++;
        }
        return count;
    }
};
