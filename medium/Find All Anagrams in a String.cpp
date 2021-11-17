/**
* Leetcode Problem- https://leetcode.com/problems/find-all-anagrams-in-a-string/
* Author - Shubham Nagaria
* Date - 17th Nov 2021
**/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res,v1(26,0),v2(26,0);
        for(auto ch:p) 
            v2[ch-'a']++;
        int n = s.size(), m=p.size();
        for(int i =0 ; i <n;i++){
            v1[s[i]-'a']++;
            
            if(i>=m)
            v1[s[i-m]-'a']--;
            
            if(v1==v2)
                res.push_back(i-m+1);
            
        }
        return res;
    }
};
