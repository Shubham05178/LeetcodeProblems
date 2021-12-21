/**
* Leetcode Problem - https://leetcode.com/problems/sorting-the-sentence/
* Author - Shubham Nagaria
* Date - 22nd Dec 2021
**/
class Solution {
public:
    string sortSentence(string s) {
    string curr="";
    map<int,string>mp;
    for(char c: s){
        if(c==' '&&curr!=""){
            int id=curr.back()-'0';
            curr.pop_back();
            mp[id]=curr;
            curr="";
            }
        else
            curr+=c;
        }
        if(curr!=""){
            int id=curr.back()-'0';
            curr.pop_back();
            mp[id]=curr;
          }
        string ans;
        for(auto i : mp )
            ans=ans+i.second+ " ";
        if(ans.back()==' ')
            ans.pop_back();
        return ans;
    }
};
