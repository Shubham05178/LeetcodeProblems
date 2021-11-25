/**
* Leetcode Problem - https://leetcode.com/problems/count-and-say
* Author - Shubham Nagaria
* Date - 25th Nov 2021
**/
class Solution {
public:
    string say(string l){
      int tmp=0;
        string says="";
        int len=l.size();
        for(int i =0; i < len;i++){
            tmp++;
            if(i==len-1 || l[i+1]!=l[i]){
                says+=char('0'+tmp);
                says+=l[i];
                tmp=0;
            }
        }
        return says;
        
    }
    string countAndSay(int n) {
        vector<string>cn(31);
        cn[1]="1";
        for(int i =2; i <=n ; i++)
            cn[i]=say(cn[i-1]);
        return cn[n];
    }
};
