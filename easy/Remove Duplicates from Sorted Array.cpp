/**
* Leetcode Problem - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
* Author - Shubham Nagaria
* Date - 11th Jan 2022
**/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0,j=0,n = nums.size()-1,c=0;
        while(j<=n){
            while(j<n && nums[j]==nums[j+1])j++;
            nums[i]=nums[j];
            i++;
            j++;
        }
        return i;
    }
};
