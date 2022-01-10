/**
* Leetcode Problem - https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
* Author - Shubham Nagaria
* Date - 11th Jan 2022
**/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j =0, n =nums.size()-1,i=0;
        int cn=0;
        while(j<=n){
            cn=1;
            while(j<n && nums[j]==nums[j+1])cn++,j++;
            nums[i]=nums[j];
            i++;
            if(cn>1)
                nums[i]=nums[j],i++;
            j++;
        }
        return i;
    }
};
