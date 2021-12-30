/**
* Leetcode Problem - https://leetcode.com/problems/find-a-peak-element-ii/
* Author - Shubham Nagaria
* Date - 31st Dec 2021
**/
//O(N logM)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), lo = 0, hi = m - 1, mid; 
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int max_row = 0;
            for (int i = 0; i < n; ++i) {
                if (matrix[max_row][mid] < matrix[i][mid])
                    max_row = i;
            }
            if ((mid == 0 || matrix[max_row][mid] > matrix[max_row][mid - 1]) && 
                (mid == m - 1 || matrix[max_row][mid] > matrix[max_row][mid + 1]))
                return {max_row, mid};
            else if (mid > 0 && matrix[max_row][mid - 1] > matrix[max_row][mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return {-1, -1};
    }
};
//O(N*M) 
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        queue<pair<int,int>>que;
        que.push({0,0});
        int n = mat.size();
        int m = mat[0].size();
        vector<int>chng={0,-1,0,1,0};
        // (0, -1) (-1,0),(0,1),(1,0)
        while(!que.empty()){
            auto front = que.front();
            que.pop();
            int x= front.first;
            int y= front.second;
            
            int cnt=0;
            for(int i =0 ; i < 4 ; i++){
                int x_= x+chng[i];
                int y_= y+chng[i+1];
                if(x_>=0 && y_>=0 && x_<n && y_<m && mat[x][y]<mat[x_][y_]){
                    cnt++;
                    que.push({x_,y_});
                }
            }
            if(cnt==0)
                return {x,y};
        }
      return {};  
    }
};
