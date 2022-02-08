/**
* Leetcode problem - https://leetcode.com/problems/add-digits/
* Author - Shubham Nagaria
* Date - 8th Feb 2022
**/
class Solution {
public:
    int addDigits(int num) {
       int sum_ =0;
        int n = num,m;
        while(n > 9){
            sum_ = 0;
            m = n;
            while(m){
                sum_+= m%10;
                m/=10;
            }
            n = sum_;
        }
        return n;
    }
};
