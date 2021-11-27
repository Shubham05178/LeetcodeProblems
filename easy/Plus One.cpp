/**
* Leetcode problem - https://leetcode.com/problems/plus-one
* Author - Shubham Nagaria
* Date - 27th Nov 2021
**/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int>res(n+1);
        int c=1;
        for(int i = n-1; i>=0; i--){
            int s=digits[i]+c;
            res[i+1]=s%10;
            c=(int)s/10;
        }
        res[0]=c;
        while(res[0]==0){
            res.erase(res.begin());
        }
        return res;
        
    }
};
