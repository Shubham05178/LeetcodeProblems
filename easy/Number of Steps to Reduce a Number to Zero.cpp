/**
Leetcode Problem - https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
Author - Shubham Nagaria
Date - 19th Dec 2021
**/
class Solution {
public:
    int numberOfSteps(int num) {
        int c=0,n=num;
        while(n){
            if((n&1)==1) {
                n-=1;
                c++;
            }
            if(n){
            c++;
            n=n>>1;
            }
        }
        return c;
    }
};
