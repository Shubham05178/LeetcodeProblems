/**
* Leetcode Problem - https://leetcode.com/problems/simplify-path/
* Author -  Shubham Nagaria=
* Date - 22nd Jan 2022
**/
class Solution {
public:
    string simplifyPath(string path) {
        string s="";
        vector<string>ans;
        for(char ch : path){
            if(ch=='/'){
                if(s==".."){
                    if(ans.size()>0)
                        ans.pop_back();
                }
                else if( s!="." && s!="")
                    ans.push_back(s);
                s="";
            }
            else{
                s+=ch;
            }
        }
        if(s==".." && ans.size()>0) ans.pop_back();
        else if(s!="." && s!="" && s!="..") ans.push_back(s);
        s="";
        for(string p: ans)
            s+="/"+p;
        return s=="" ? "/" : s;
    }
};
