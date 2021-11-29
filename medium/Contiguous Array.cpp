/**
* Leetcode Problem- https://leetcode.com/problems/contiguous-array/
* Author - Shubham Nagaria
* Date - 29th Nov 2021
**/
class Solution {
public:
  int findMaxLength(vector<int>& nums) {
   unordered_map<int,int>smp={{0,-1}};
      int ans=0,s=0;
      for(int i =0 ; i<nums.size();i++){
          s+=nums[i]?1:-1;
          if(smp.count(s))
              ans=max(ans,i-smp[s]);
          else
              smp[s]=i;       
      }
      return ans;
  }
};
