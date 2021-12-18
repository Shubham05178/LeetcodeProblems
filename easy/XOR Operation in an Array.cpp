/**
* Leetcode Problem - https://leetcode.com/problems/xor-operation-in-an-array/
* Author - Shubham Nagaria
* Date - 18th Dec 2021
**/
class Solution {
public:
    int xorOperation(int n, int start) {
        int x=0;
        for(int i = 0; i<n;i++)
            x^=(i+i+start);
        return x;
    }
};
