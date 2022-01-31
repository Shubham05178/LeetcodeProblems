/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-278/problems/keep-multiplying-found-values-by-two/
* Author - Shubham Nagaria
* Date - 1st Feb 2022
**/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>s(nums.begin(),nums.end());
        while(s.find(original)!= s.end()){
            original = original<<1;
        }
        return original;
    }
};
