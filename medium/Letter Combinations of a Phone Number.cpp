/**
* Leetcode Problem - https://leetcode.com/problems/letter-combinations-of-a-phone-number/
* Author - Shubham Nagaria
* Date - 31st Dec 2021
**/
class Solution {
public:
    unordered_map<char,string>m;
        void helper(string& digits,vector<string>& res,int c,string s){
            if(c==digits.size()){ 
                res.push_back(s);
                return;
            }
            for(char ch: m[digits[c]])
                helper(digits,res,c+1,s+ch);    
                
        }
    
    vector<string> letterCombinations(string digits) {
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        vector<string>res;
        string s="";
        if(digits.size()==0) return res;
        helper(digits,res,0,s);
        return res;
    }
};
