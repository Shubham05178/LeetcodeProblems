/**
* Leetcode Problem - https://leetcode.com/problems/unique-paths/
* Author - Shubham Nagaria
* Date - 2nd Nov 2021
**/
class Solution {
public:
    vector<vector<int>>dp;
    int dfs(int x,int y,int m,int n)
    {
        if(x==m-1 and y==n-1)return 1;
        if(x>m-1 or y>n-1 or x<0 or y<0)return 0 ;
        if(dp[x][y]!=-1)return dp[x][y];
        return dp[x][y]=dfs(x+1,y,m,n)+dfs(x,y+1,m,n);
    }
    int uniquePaths(int m, int n) {
        dp.resize(m+1,vector<int>(n+1,-1));
       return dfs(0,0,m,n);
       
    }
};
