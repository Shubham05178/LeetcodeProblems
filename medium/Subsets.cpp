/**
* Leetcode Problem - https://leetcode.com/problems/subsets/
* Author - Shubham Nagaria
* Date - 13th Feb 2022
**/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int p= 1<<n;
        vector<vector<int>>res;
        vector<int>temp;
        for(int i =0; i < p ; i++){
                for(int j =0; j <n;j++){
                    if(i&(1<<j))temp.push_back(nums[j]);
                }
                res.push_back(temp);
                temp.clear();
            }
        return res;
    }
};
