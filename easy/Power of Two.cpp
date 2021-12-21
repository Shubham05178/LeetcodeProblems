/**
Leetcode Problem - https://leetcode.com/problems/power-of-two/
Author - Shubham Nagaria
Date - 22th Dec 2021
**/
class Solution {
public:
    bool isPowerOfTwo(int n) {
         if(n<=0) return false;
        return !(n&(n-1));
    }
};
