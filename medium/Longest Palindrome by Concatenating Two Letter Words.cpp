/**
* Leetcode Problem - https://leetcode.com/contest/biweekly-contest-69/problems/longest-palindrome-by-concatenating-two-letter-words/
* Author - Shubham Nagaria
* Date - 9th Jan 2022
**/
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>s;
        int l =0;
        int c=0;
        string str1;
        for(string& str: words){
            str1=str;
            reverse(str1.begin(),str1.end());
            if (s[str1]!=0){
                l+=4;
                s[str1]--;
                if(str1[1]==str1[0]) c--;
            }
                else{
                s[str]++;
                if(str[0]==str[1]) c++;
            }
        }
        if(c>0) l+=2;
        return l;
    }
};
