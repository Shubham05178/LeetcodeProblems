/**
* Leetcode Problem - https://leetcode.com/problems/reverse-pairs/
* Author - Shubham Nagaria
* Date - 24th Dec 2021
**/

//O(n log n) time complexity and O(n) space complexity
class Solution {
public:
    int merge(vector<int>&nums, int left, int mid, int right){
        int l= right-left+1;
        int temp[l];
        int i=left,j=mid;
        int count=0;
        int ptr=0;
        while(i<mid && j<=right){
            long int wd= ((long int)nums[j])*2;
            long int pd=((long int) nums[i]);
                if(pd>wd)
                {   count+=mid-i;
                    j++;
                }
            else
                i++;
        }
        i=left,j=mid;
        while(i<mid && j<=right){
            if(nums[i]>nums[j])
                temp[ptr++]=nums[j++];
            else
                temp[ptr++]=nums[i++];
        }
        while(i<mid) temp[ptr++]=nums[i++];
        while(j<=right) temp[ptr++]=nums[j++];
        ptr=0;
        while(ptr<l){
            
            nums[ptr+left]=temp[ptr];
            ptr++;
        }
        return count;
    }
    int inversion(vector<int>& nums, int left, int right){
        if(left==right)
            return 0;
        int mid = left+ ((right-left)/2);
        int a=inversion(nums,left,mid);
        int b=inversion(nums,mid+1,right);
        int c= merge(nums,left,mid+1,right);
        return a+b+c;
    }
    int reversePairs(vector<int>& nums) {
        return inversion(nums,0,nums.size()-1);
    }
};

