/**
* Leetcode Problem - https://leetcode.com/problems/reshape-the-matrix/
* Author - Shubham Nagaria
* Date - 4th Jan 2022
**/

//Single loop iteration: Time Complexity O(n*m) Space Complexity - O(r*c)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat[0].size(), n = mat.size();
        int total = m *n;
        if(total!= (r*c))
            return mat;
        vector<vector<int>>res(r,vector<int>(c));
        for(int i =0; i < total ; i++) 
            res[i/c][i%c]= mat[i/m][i%m];
        return res;
    }
};
//Nested loop iteration: Time Complexity O(n*m) Space Complexity - O(r*c)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if(n*m != r*c)
            return mat;
        vector<vector<int>>res;
        vector<int>inter_;
        int co=0;
        for(int i =0; i < n; i++){
            for (int j =0; j< m;j++){
                {   co++;
                    inter_.push_back(mat[i][j]);
                    if(co==c) co=0, res.push_back(inter_),inter_={};
                }
            }
        }
        return res;
    }
};
