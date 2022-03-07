/**
* Leetcode Problem - https://leetcode.com/problems/largest-number/
* Author - Shubham Nagaria
* Date - 8th March 2022
**/
class Solution {
public:
    bool static comp(int a, int b){
        string s1 = to_string(a);
        string s2= to_string(b);
        if(s1+s2> s2+s1)
            return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        if(nums[0]==0) return "0";
        string s ="";
        for(int i : nums)
            s+=to_string(i);
        return s;
    }
};
