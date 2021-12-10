/**
* Leetcode Problem- https://leetcode.com/problems/ugly-number/
* Author - Shubham Nagaria
* Date - 11th Dec 2021
**/
class Solution {
public:
    bool isUgly(int n) {
        if(n<1)
            return false;
        if(n<7)
            return true;
        while(true){
            if(n%2==0) n/=2;
            else if(n%5==0)n/=5;
            else if(n%3==0)n/=3;
            else break;
        }
        if(n==1)
            return true;
        return false;
    }
};
