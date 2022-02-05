/**
* Leetcode Problem - https://leetcode.com/problems/next-greater-element-iii/
* Author - Shubham Nagaria
* Date - 6th Feb 2022
**/
class Solution {
public:
    int nextGreaterElement(int n) {
        string s= to_string(n);
        if(!next_permutation(s.begin(),s.end()))
            return -1;
        long x=stol(s,nullptr,10);
        if (x>INT_MAX) return -1;
        return x;
    }
};
