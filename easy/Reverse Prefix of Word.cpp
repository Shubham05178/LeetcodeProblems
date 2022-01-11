/**
* Leetcode Problem - https://leetcode.com/problems/reverse-prefix-of-word/
* Author - Shubham Nagaria
* Date - 11th Jan 2022
**/
class Solution {
public:
    string reversePrefix(string word, char ch) {
        string res="";
        bool fl=true;
        for(char c:word){
            if(fl) res=c+res;
            else res+=c;
            if(c==ch && fl)
                fl=false; 
        }
        if(fl) return word;
        return res;
    }
};
