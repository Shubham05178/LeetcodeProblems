/**
* Leetcode Problem - https://leetcode.com/problems/unique-paths-iii/
* Author - Shubham Nagaria 
* Date - 2nd Nov 2021
**/
class Solution {
public:
    int empty=1,res=0;
    void dfs(vector<vector<int>>& grid,int x,int y,int zount){
        if(x<0||y<0|| x>=grid.size() || y >=grid[0].size() || grid[x][y]==-1)
            return;
        if(grid[x][y]==2){
            if(empty==zount)res++;
            return;
        }
        
        grid[x][y]=-1;
        dfs(grid,x+1,y,zount+1);
        dfs(grid,x,y+1,zount+1);
        dfs(grid,x-1,y,zount+1);
        dfs(grid,x,y-1,zount+1);
        
        grid[x][y]=0;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m= grid.size(),n=grid[0].size();
        int sx=0,sy=0;
        for(int i =0; i<m; i++){
            for(int j=0;j<n;j++){
                if (grid[i][j]==0) 
                    empty++;
                else if ( grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
            }
        }
        dfs(grid,sx,sy,0);
        return res;
    }
};
