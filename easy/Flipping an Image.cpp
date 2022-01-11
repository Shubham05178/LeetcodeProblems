/**
* Leetcode Problem - https://leetcode.com/problems/flipping-an-image/
* Author - Shubham Nagaria
* Date - 11th Jan 2022
**/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m = image[0].size();
        for(auto& row : image){
            reverse(row.begin(),row.end());
            for(auto &j :row)
                j^=1;
        }
        return image;
    }
};
