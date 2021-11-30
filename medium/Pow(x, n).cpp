/**
* Leetcode Problem - https://leetcode.com/problems/powx-n/
* Author - Shubham Nagaria  
* Date - 30th Nov 2021
**/
class Solution {
public:
    	double Pow(double x, int n){
        if(n==0){
            return 1;
        }
        return (n%2==0) ? Pow(x*x, n/2) : Pow(x*x, n/2)*x;
    }
    
    double myPow(double x, int n) {
        long m = n;
        if(m<0){
            m *= -1;
            x = 1/x;
        }
        return Pow(x,m);
    }
};
