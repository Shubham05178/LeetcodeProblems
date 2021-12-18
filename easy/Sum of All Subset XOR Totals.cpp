/**
Leetcode Problem - https://leetcode.com/problems/sum-of-all-subset-xor-totals/
Author - Shubham Nagaria
Date - 19th Dec 2021
**/
class Solution {
public:
int power(int a, int b){
        if(b ==0)
            return 1;
        if(b==1)
            return a;
        int x= power(a,b/2);
        if((b&1)==0)
            return x*x;
        else
            return a*x*x;
    }
    int subsetXORSum(vector<int>& nums) {
       int n = nums.size();
        int pow= power(2,n);
        int res=0;
        for(int i =0; i <pow;i++){
            int x=0;
            for(int j =0; j<n;j++){
                if(i& (1<<j))
                    x^=nums[j];
            }
            res+=x;
        }
        return res;
    }
};
