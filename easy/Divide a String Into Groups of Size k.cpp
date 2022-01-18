/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-276/problems/divide-a-string-into-groups-of-size-k/
* Author - Shubham Nagaria
* Date - 19th Jan 2022
**/
class Solution {
public:
    vector<string> divideString(string ss, int k, char fill) {
        int s=0;
        string vs;
        vector<string>ans;
    for(char& ch :ss){
            s++;
            vs+=ch;
            if(s==k){
                ans.push_back(vs);
                s=0;
                vs="";
            }
    }
        if(s!=0 && s!=k){
            while(s<k){
                vs+=fill;
                s++;
            }
            ans.push_back(vs);
        }
        return ans;
    }
};
