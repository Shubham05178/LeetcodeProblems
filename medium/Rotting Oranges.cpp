/**
* Leetcode Problem -https://leetcode.com/problems/rotting-oranges/
* Author - Shubham Nagaria  
* Date 29th Oct 2021
**/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
        
        queue<pair<int,int>>q;
        //to move in four direction
        vector<int> dir={-1,0,1,0,-1};
        //to count how many fresh oranges we have to rot
        int fresh_oranges=0;
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                    fresh_oranges++;
            }
        }
        
        int ans=-1;
        
        while(!q.empty()){
            
            int N=q.size();
            
            for(int i=0;i<N;i++){
                pair<int,int>tmp=q.front();
                q.pop();
                //initializing this loop for the movement in four direction
                for(int j=0;j<4;j++){
                    
                    int a=tmp.first+dir[j];
                    int b=tmp.second+dir[j+1];
                    //we would perform any operation only when encountered with a fresh oranges
                    //checking the boundaries and fresh oranges
                    if(a>=0 && a<m && b<n && b>=0 && grid[a][b]==1){
                        
                        grid[a][b]=2;
                        q.push({a,b});
                        fresh_oranges--;
                    }
                }
                
            }
            ans++;
            
        }
        //if perfoming all operation still fresh oranges have been left
        if(fresh_oranges>0) return -1;
        
        return ans==-1?0:ans;
    }
};
