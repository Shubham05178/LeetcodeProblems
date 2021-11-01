/**
* Leetcode problem - https://leetcode.com/problems/surrounded-regions/
* Author - Shubham Nagaria
* Date- 1st Nov 2021
**/

class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j){
        if(board[i][j]=='O'){
            board[i][j]='F';
            if(i+1 < board.size()) dfs(board,i+1,j);
            if(j+1<board[0].size()) dfs(board,i,j+1);
            if(i>1) dfs(board,i-1,j);
            if(j>1) dfs(board,i,j-1);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m==0){
            return;
        }
        int n=board[0].size();
        //first row and last row
        for(int i=0;i<n;i++){
            dfs(board,0,i);
            dfs(board,m-1,i);
        }
        //first col and last col
        for (int i =0;i<m;i++){
            dfs(board,i,0);
            dfs(board,i,n-1);
        }
        for (int i =0; i<m;i++){
            for ( int j =0; j <n;j++){
                if(board[i][j]=='F')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};
