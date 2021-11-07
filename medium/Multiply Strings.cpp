/**
* Leetcode Problem - https://leetcode.com/problems/multiply-strings/
* Author - Shubham Nagaria
* Date - 7 Nov 2021
**/


class Solution {
public:
    string multiply(string& A, string& B) {
        if(A == "0" || B == "0") return "0";
        string ans(size(A)+size(B), '0');
        for(int i = size(A)-1; i >= 0; i--) {
            for(int j = size(B)-1; j >= 0; j--) {
                
                int res = (ans[i+j+1]-'0') + (A[i]-'0') * (B[j]-'0');
                ans[i+j+1] = res%10 + '0';  // ones place of multiplication result
                ans[i+j] += res/10;         // carry over to previous index if result >= 10
             cout<<ans[i+j+1]<<(i+j+1)<<endl;
            cout<<ans[i+j]<<(i+j)<<endl;
            }
        }
        if(ans[0] == '0') return ans.substr(1);
        return ans;
    }
};

