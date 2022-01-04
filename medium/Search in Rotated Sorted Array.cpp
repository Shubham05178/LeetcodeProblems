/**
* Leetcode Problem - https://leetcode.com/problems/search-in-rotated-sorted-array/
* Author - Shubham Nagaria
* Date - 4th Jan 2022
**/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int h = nums.size()-1;
        int l =0;
        while(l<h){
            int mid =l+ ((h-l)/2);
            if(nums[mid]> nums[h]) l=mid+1;
            else h=mid;
        }
        int r=l;
        int n = nums.size();
        l=0,h=nums.size()-1;
        while(l<=h){
            int mid = l+ ((h-l)/2);
            int rmid= (mid+r)%n;
            if(nums[rmid]==target) return rmid;
            else if (nums[rmid]<target) l= mid+1;
            else h = mid-1;
        }
        return -1;
    }
};
