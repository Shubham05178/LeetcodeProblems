/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-278/problems/all-divisions-with-the-highest-score-of-a-binary-array/
* Author - Shubham Nagaria
* Date - 1st Feb 2022
**/
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i : nums){
            mp[i]++;
        }
        int n = nums.size();
        vector<int>res;
        int max_= INT_MIN;
        int z=0;
        for(int i =0; i <= n;i++){
            if( z + mp[1] > max_)
            {
                max_= z+mp[1];
                res.clear();
                res.push_back(i);
            }
            else if(z+mp[1] == max_)
                    res.push_back(i);
            if(i<n){
                mp[nums[i]]--;
            z = nums[i]==0 ? z+1:z;
            }
        }
        return res;
    }
};
