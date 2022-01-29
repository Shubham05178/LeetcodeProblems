/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-277/problems/find-all-lonely-numbers-in-the-array/
* Author - Shubham Nagaria
* Date - 30th Jan 2022
**/
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int , int> mp;
        for(int i : nums)
            mp[i]++;
        vector<int>res;
        for(int i : nums){
            if(mp[i]==1){
                if(mp[i-1]==0 && mp[i+1]==0)
                    res.push_back(i);
            }
        }
        return res;
    }
};
