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






class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        vector<string>p;
        string name;
        for(char c: path){
            if ( c == '/') {
               if(name.size() == 0) continue; 
               if(name == ".."){
                   if(p.size() > 0)
                       p.pop_back();
               }
               else if(name != ".")
                 p.push_back(name);
               name.clear();
              }
              else name.push_back(c);
        }
        string res;
        if(p.size()==0) return "/";
        for(int i =0; i < p.size();i++)
            res.append("/"+ p[i]);
        return res;
    }
};
