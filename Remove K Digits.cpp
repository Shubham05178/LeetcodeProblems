/**
* Leetocode Problem - https://leetcode.com/problems/remove-k-digits/
* Author - Shubham Nagaria
* Date - 18th Feb 2022
**/
class Solution {
public:
    string removeKdigits(string num, int k) {
          string ans = "";                                  
       for (char c : num) {
           while (ans.length() && ans.back() > c && k) {
               ans.pop_back();                                 
               k--;       
           }
           if (ans.length() || c != '0')  ans.push_back(c);   
       }
       
       while (ans.length() && k--) ans.pop_back(); 
       return ans.empty() ? "0" : ans;
    }
};
