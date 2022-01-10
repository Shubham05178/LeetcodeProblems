/**
* Leetcode Problem - https://leetcode.com/problems/container-with-most-water/ 
* Author - Shubham Nagaria
* Date - 11th Jan 2021
**/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0, j = height.size()-1,ans=0;
        while(i<j){
            ans = max(ans,(j-i)*min(height[i],height[j]));
            if(height[i] > height[j])
                j--;
            else  i++;
        }
        return ans;
    }
};
