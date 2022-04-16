/**
Leetcode Problem - https://leetcode.com/problems/binary-number-with-alternating-bits/
Author - Shubham Nagaria
Date - 19th Dec 2021
**/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int p=2;
        
        
        
        while(n){
            if(n&1==1){ 
                if(p!=2 && p!=0) return false;
                p=1;
            }
            else
            {
                if(p!=1&& p!=2) return false;
                p=0;
            }
            n=n>>1;
        }
        return true;
    }
};
