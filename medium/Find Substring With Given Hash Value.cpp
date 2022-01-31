/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-278/problems/find-substring-with-given-hash-value/
* Author - Shubham Nagaria
* Date - 1st Feb 2022
**/
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long  hash = 0, idx = 0, p = 1, n = s.size(); 
        for(int i = n - 1; i >=0; --i){
            hash =  ( hash * power + s[i] - 'a' + 1) % modulo;
            if(i + k >= n) 
                p = (p * power) % modulo;
            else
                hash = ((( hash - (s[i + k] -'a' + 1) * p) % modulo) + modulo) % modulo;
            if(hash == hashValue)
              idx=i;
        }
     return s.substr(idx,k); 
    } 
};
