/**
* Leetcode Problem - https://leetcode.com/contest/biweekly-contest-69/problems/capitalize-the-title/
* Author - Shubham Nagaria
* Date - 9th Jan 2022
**/
class Solution {
public:
    string capitalizeTitle(string title) {
       string s= "";
        int N = title.length();
        for(int i =0; i < N ; i++){
            char c= title[i];
            if(c>='A' && c<='Z')
                c=c+32;
            if(i+2<N && title[i+1]!=' ' && title[i+2]!=' ' && ( i ==0 || title[i-1]==' '))
                c=c-32;
            s+=c;
        }
        return s;
    }
};
