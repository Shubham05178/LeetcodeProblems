/**
* Leetcode Problem - https://leetcode.com/problems/coin-change/
* Author - Shubham Nagaria
* Date - 8th Nov 2021
**/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                } else {
                    break;
                }
            }
        }
        if (dp[amount] > amount) 
            return -1;
        return dp[amount];
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,amount+1));
        dp[n][amount]=-1;
        for(int i =0 ; i <n+1;i++){
            for ( int j =0 ; j < amount+1;j++){
                if(j==0){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0)
                    continue;
                if(coins[i-1]<=j){
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[n][amount]>amount)
            return -1;
        return dp[n][amount];
    }
};
