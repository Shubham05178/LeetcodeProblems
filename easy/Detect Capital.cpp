/**
* Leetcode Problem - https://leetcode.com/problems/detect-capital/
* Author - Shubham Nagaria
* Date - 24th Jan 2022
**/
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n ==1) return true;
        bool first = word[0] >='A' && word[0] <= 'Z' ? true : false;
        bool second = word[1] >= 'A' && word[1] <= 'Z' ? true : false;
        if( !first && second) return false;
        bool nxt = first && second ? true:false; 
        bool nxtcurr;
        for(int i =2; i < n; i++){
            nxtcurr = word[i] >= 'A' && word[i]<='Z'? true:false;
            if(nxt!=nxtcurr)
                return false;
        }
        return true;
    }
};
