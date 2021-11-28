/**
* Leetcode Problem - https://leetcode.com/problems/minimum-size-subarray-sum
* Author - Shubham Nagaria
* Date - 29 Nov 2021

**/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
{       int n =nums.size();
        int ans=INT_MAX,left=0,su=0;
        for(int i =0;i < n;i++){
            su+=nums[i];
            while(su>=s){
                ans=min(ans,i-left+1);
                su-=nums[left++];
            }
            
            
        }
 return ans!=INT_MAX?ans:0;
}
};
