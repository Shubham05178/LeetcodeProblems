/**
* Leetcode Problem - https://leetcode.com/problems/unique-paths-ii/
* Author - Shubham Nagaria
* Date - 2nd Nov 2021
**/

class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n){
        if(i>=m || j >= n || obstacleGrid[i][j]==1)
            return 0;
        if(i==m-1 && j == n-1)
            return 1;
 
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=dfs(obstacleGrid,i+1,j,m,n)+dfs(obstacleGrid,i,j+1,m,n);
        
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        dp.resize(m+1,vector<int>(n+1,-1));
       return dfs(obstacleGrid,0,0,m,n);
        
    }
};
