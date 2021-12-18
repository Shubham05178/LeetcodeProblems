/**
* Leetcode Problem - https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
* Author - Shubham Nagaria
* Date- 18th Dec 2021
**/
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        int k = s.size();
       int l= digits.size();
        vector<int>dp(k+1,0);
        dp[k]=1;
        
        for( int i = k-1; i >=0; i--){
            int Si= s[i]-'0';
            for(auto &d : digits){
                if(stoi(d) < Si)
                    dp[i]+= pow(l,k-i-1);
                else if(stoi(d)==Si)
                    dp[i]+=dp[i+1];
            }
            
        }
        for(int i =1; i <k;i++)
            dp[0]+=pow(l,i);
        return dp[0];
    }
};
