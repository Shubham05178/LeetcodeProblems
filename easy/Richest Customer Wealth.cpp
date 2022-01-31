/**
* Leetcode Problem - https://leetcode.com/problems/richest-customer-wealth/
* Author - Shubham Nagaria
* Date - 31st Jan 2022
**/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_ = INT_MIN;
        int n = accounts.size();
        int m = accounts[0].size();
        for(int i = 0; i < n ; i++){
            for(int j = 1; j < m; j++)
            accounts[i][j] = accounts[i][j] + accounts[i][j-1];
        if(accounts[i][m-1]>max_)
            max_= accounts[i][m-1];
        }
        return max_;
    }
};
