/**
* Author - Shubham Nagaria
* Leetcode Problem - https://leetcode.com/problems/pascals-triangle-ii/
* Date - 1st Nov 2021
**/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>dp(rowIndex+1);
        dp[0]=1;
        for( int i =1;i<rowIndex+1;i++){
            for( int j = i;j >0;j--)
                dp[j]+= dp[j-1];
        }
        return dp;
    }
};
