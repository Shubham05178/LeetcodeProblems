/**
* Leetcode Problem - https://leetcode.com/problems/spiral-matrix/
* Author - Shubham Nagaria
* Date - 1st Jan 2022
**/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom= matrix.size()-1;
        int right= matrix[0].size()-1;
        int left =0;
        vector<int>res;
        while(top<=bottom && left<=right){
            for(int c= left; c<=right;c++)
                res.push_back(matrix[top][c]);
            top++;
            if(top>bottom)
                break;
            for(int r = top ; r<=bottom; r++)
                res.push_back(matrix[r][right]);
            right--;
            if(right<left)
                break;
            for(int c = right; c>=left;c--)
                res.push_back(matrix[bottom][c]);
            bottom--;
            if(bottom<top)
                break;
            for(int r= bottom ; r>=top;r--)
                res.push_back(matrix[r][left]);
            left++;
            if(left>right)
                break;
        }
        return res;
    }
};
