/**
* Leetcode Problem - https://leetcode.com/problems/contains-duplicate-ii/
* Author - Shubham Nagaria
* Date- 16th Nov 2021
**/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int , int> res;
        int i =0, j=0,n=nums.size(),x;
        while(j<n){
            
            if(j>k)
                res[nums[i++]]=0;
            
                x=nums[j++];
            
                if (res[x])
                    return true;
                    
                res[x]=1;
        }
        return false;
    }
};
