/**
* Leetcode Problem - https://leetcode.com/problems/find-peak-element/
* Author - Shubham Nagaria
* Date - 3rd Jan 2022
**/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int h = nums.size()-1;
        int n =h;
        int l =0;
        int mid;
        while(l<=h){
            mid = l+((h-l)/2);
            if((mid==0||nums[mid]>nums[mid-1])&&(mid==n||nums[mid]>nums[mid+1])) return mid;
            else if (mid==0||nums[mid]>nums[mid-1]) l=mid+1;
            else h=mid-1;  
        }
        return mid;
    }
};
