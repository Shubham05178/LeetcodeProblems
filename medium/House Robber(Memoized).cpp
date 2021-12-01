/**
* Leetcode Problem - https://leetcode.com/problems/house-robber/
* Author - Shubham Nagaria
* Date - 01st Dec 2021
**/
class Solution {
public:
    vector<int>dp;
  int maxAmount(vector<int>&arr, int i,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=max(arr[i]+maxAmount(arr,i+2,n), maxAmount(arr,i+1,n));
        
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        dp.resize(n,-1);
       return maxAmount(nums,0,n);
    }
};
