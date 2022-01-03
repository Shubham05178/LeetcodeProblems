/**
* Leetcode Problem - https://leetcode.com/problems/peak-index-in-a-mountain-array/
* Author - Shubham Nagaria
* Date - 3rd Jan 2022
**/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int h=arr.size()-2;
        int l=1;
        int mid;
        while(l<=h){
            mid = (l+h)>>1;
            if(arr[mid]>arr[mid-1]&& arr[mid]>arr[mid+1]) return mid;
            else if (arr[mid]>arr[mid-1]) l=mid+1;
            else h=mid-1;  
         }
         return mid;
    }
};
