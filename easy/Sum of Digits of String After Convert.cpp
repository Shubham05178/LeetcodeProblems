/**
* Leetcode Problem - https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
* Author - Shubham Nagaria
* Date - 8th Feb 2022
**/
class Solution {
public:
    int getLucky(string s, int k) {
        long long int n = 0;
        for(char ch : s){
            int x= (ch-'a'+1);
            while(x){
                n += x%10;
                x/=10;
            }
        }
        long long int  m, sum_ = 0;
        while(--k){
            m=n;
            sum_=0;
            while(m){
                sum_ += m%10;
                m/=10;
            }
            n = sum_;
        }
        return n;
    }
};
