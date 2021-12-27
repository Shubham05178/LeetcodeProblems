/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-272/problems/find-first-palindromic-string-in-the-array/
* Author - Shubham Nagaria
* Date - 28th Dec 2021
**/
class Solution {
public:
   bool palindrome(string s){
        int n =s.size();
       int i=0;
       int m =n-1;
       while(i*2<n){
           if(s[i]!=s[m-i])
               return false;
            i++;
       }
       return true;
   }
    string firstPalindrome(vector<string>& words) {
        int N = words.size();
        for( int j =0; j < N;j++){
            if(palindrome(words[j]))
                return words[j];
        }
        return "";
    }
};
