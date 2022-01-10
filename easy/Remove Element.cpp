/**
* Leetcode Problem - https://leetcode.com/problems/remove-element/
* Author - Shubham Nagaria
* Date - 11th Jan 2022
**/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i =0;
        int n = nums.size()-1;
        int k =0,j=n;
        while(i<n){
            while(i<n && nums[i]!=val)i++;
            while(i<n && nums[n]==val)n--;
            swap(nums[i],nums[n]);
        }
        while(k<=j && nums[k]!=val) k++;
        return k;
    }
};
