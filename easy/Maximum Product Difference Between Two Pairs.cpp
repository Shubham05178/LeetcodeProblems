/**
Leetcode Problem - https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
Author - Shubham Nagaria
Date - 22th Dec 2021
**/

// Time Complexity - O(N Log N)

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
   sort(nums.begin(),nums.end());
        int n =nums.size();
        return (nums[n-1]*nums[n-2])-(nums[0]*nums[1]);
    }
}; 

// Time Complexity - O(N)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int a=0;
        int b=0,c=1e4+1,d=1e4+1;
        for(int i : nums){
            if (i>a || i >b){
                a=max(a,b);
                b=i;
            }
            if(i<c || i < d){
                c=min(c,d);
                d=i;
            }
        }
        return (a*b) - (c*d);
    }
};
