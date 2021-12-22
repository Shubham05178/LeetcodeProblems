/**
* Leetcode Problem - https://leetcode.com/contest/biweekly-contest-59/problems/maximum-matrix-sum/
* Author - Shubham Nagaria  
* Date - 22nd Dec 2021 
**/
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long int s=0,sneg=0;
        int c=0;
        int mi=INT_MAX;
        int n=matrix.size(),m=matrix[0].size();
        for(int i =0 ; i < n; i++){
            for(int j =0; j <m; j++){
                int x=abs(matrix[i][j]);
                s+=x;
                mi=min(mi,x);
                if(matrix[i][j]<0) c++;
            }
        }
            if((c&1)!=0)
                s-=(2*mi);
                
        return s;
    }
};
