/**
Leetcode Problem - https://leetcode.com/problems/gray-code/
Author - Shubham Nagaria
Date - 19th Dec 2021
**/

class Solution {
public:
    vector<int> grayCode(int n) {
     vector<int> res={0};
        for( int i =0 ; i < n ; i++){
            int currsize= res.size();
            for(int j = currsize-1; j >=0; j--){
                res.push_back(res[j]+(1<<i));
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n);
        for (int i=0; i<(1<<n); i++) 
            ans[i] = i^(i>>1);
        return ans;
    }
};
