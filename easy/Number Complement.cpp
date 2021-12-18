/**
Leetcode Problem - https://leetcode.com/problems/number-complement/
Author - Shubham Nagaria
Date - 19th Dec 2021
**/
class Solution {
public:
    int findComplement(int num) {
       int x=0;
        int i=0;
        do{
            if((num&1)==0) x|=1<<i;
            i++;
            num=num>>1;
        }
        while(num);
        return x;
    }
};
