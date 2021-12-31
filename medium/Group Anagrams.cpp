/**
* Leetcode Problem -  https://leetcode.com/problems/group-anagrams/
* Author - Shubham Nagaria
* Date - 1st Jan 2022
**/
//O(N * Llog L) 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {    
    unordered_map<string,vector<string>>m;
    string s;
    for(string i : strs){
        s=i;
        sort(s.begin(),s.end());
        m[s].push_back(i);
    }
    vector<vector<string>> res;
    for (auto i : m) res.push_back(i.second);
             
    return res;
    }
};

//O(N* L) sorting because of count sort
class Solution {
public:
    string countSort(string s){
        int co[26]={0};
        for(char ch: s)
            co[ch-'a']++;
        string t="";
        for(int i =0; i <26; i++){
            while(co[i]--) t+=(i+'a');            
        }
        return t;
        
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {    
    unordered_map<string,vector<string>>m;
    string s;
    for(string i : strs){
        s=i;
        
        m[countSort(s)].push_back(i);
    }
    vector<vector<string>> res;
    for (auto i : m) res.push_back(i.second);
             
    return res;
    }
};
