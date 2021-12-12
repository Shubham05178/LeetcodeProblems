/**
* Leetcode Problem - https://leetcode.com/problems/partition-equal-subset-sum/
* Author -Shubham Nagaria
* Date - 12th Dec 2021
**/

class Solution {
public:
    bool subsetsum(vector<int>& nums,int s){
        int n = nums.size();
        bool dp[n+1][s+1];
        memset(dp,false,sizeof(dp));
        for(int i = 0 ; i < n+1; i++){
            for(int j =0 ; j < s+1; j++){
                if(j==0) dp[i][j]=true;
                if(i==0) continue;
                if (nums[i-1]<=j) dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][s];
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(auto i :nums) s+=i;
        if(s%2==0) return subsetsum(nums,s/2);
        return false;
    }
};
