/**
Leetcode Problem - https://leetcode.com/problems/complement-of-base-10-integer/
Author - Shubham Nagaria
Date - 19th Dec 2021
**/
class Solution {
public:
    int bitwiseComplement(int n) {
         int x=0;
        int i=0;
        do{
            if((n&1)==0) x|=1<<i;
            i++;
            n=n>>1;
        }
        while(n);
        return x;
    }
};
