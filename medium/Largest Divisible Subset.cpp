/**
* Leetcode problem - https://leetcode.com/problems/largest-divisible-subset/
* Author- Shubham Nagaria
* Date- 15th Nov 2021
**/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        int imax=0;
        vector<int>dp(n,0),child(n,-1),ans;
        for(int i =1; i <n;i++){
            for(int j =0; j < i ; j++){
                
                if(nums[i]%nums[j]==0){
                    
                    if(dp[j]+1>dp[i]){
                        
                        dp[i]=1+dp[j];
                        child[i]=j;
                    }
                }
            }
                if (dp[imax]<dp[i])
                    imax=i;
        }
        while(imax!=-1){
            ans.push_back(nums[imax]);
            imax=child[imax];
        }
        return ans;
    }
};
