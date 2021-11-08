/**
* Leetcode Problem - https://leetcode.com/problems/coin-change-2/
* Author - Shubham Nagaria
* Date - 8th Nov 2021
**/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m=coins.size();
        vector<vector<int>>dp(m+1,vector<int>(amount+1,0));
        for( int i =0; i < m+1;i++){
            for(int j =0; j < amount+1;j++){
                if(j==0){
                    dp[i][j]=1;
                    continue;
                }
                if(i==0)
                    continue;
                if (coins[i-1]<=j)
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
                
            }
        }
        return dp[m][amount];
    }
};
