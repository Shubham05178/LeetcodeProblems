/**
* Leetcode Problem - https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
* Author - Shubham Nagaria
* Date - 8th Feb 2022
**/
class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());
        return (s[0]-'0'+s[1]-'0')*10 + (s[2]-'0'+s[3]-'0');
    }
};
