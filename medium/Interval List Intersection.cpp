/**
* Leetcode Problem- https://leetcode.com/problems/interval-list-intersections/
* Author -Shubham Nagaria
* Date- 24th Nov 2021
**/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& list1, vector<vector<int>>& list2) {
        vector<vector<int>> ans;
        int m = list1.size(), n = list2.size(), i = 0, j = 0;
        while(i < m && j < n){
            int l = max(list1[i][0], list2[j][0]);
            int r = min(list1[i][1], list2[j][1]);
            if(l<=r) ans.push_back({l, r});
            
            if(list1[i][1] < list2[j][1]) i++;
            else j++;
        }
    return ans;
    }
};

