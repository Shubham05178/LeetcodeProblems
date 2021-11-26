/**
* Leetcode Problem - https://leetcode.com/problems/first-missing-positive/
* Author - Shubham Nagaria 
* Date- 25th Nov 2021
**/
//O(n) time complexity O(n) space complexity 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        n++;
        
        for(int i : nums){
            if (i>0 && i<n){
                c[i]++;
            }    
        }
        for(int i =1; i<n;i++){
            if(c[i]==0)
                return i;
        }
        return n;
    }
};
//Time Complexity - O(n) space complexity O(1)
class Solution {
public:
    
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for( int i =0; i < n;i++){
            while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            
        
        }
        for( int i =0; i <n ; i++){
            
            if(i+1!=nums[i])
                return i+1;
        }
        return n+1;
    }
};
