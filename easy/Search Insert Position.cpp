/**
* Leetcode Problem- https://leetcode.com/problems/search-insert-position
* Author - Shubham Nagaria
* Date - 9th Nov 2021
**/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int n= nums.size();
        int i =0,j=n-1;
        int mid;
        while(i<=j){
            mid = (int)(i+(j-i)/2);
            if (target ==nums[mid])
                return mid;
            else if(target>nums[mid])
                i=mid+1;
            else
                j=mid-1;
        }
        return i;
        
    }
};
