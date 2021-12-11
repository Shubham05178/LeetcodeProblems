/**
Leetcode Problem - https://leetcode.com/problems/ugly-number-ii/
Author - Shubham Nagaria
Date - 11th Dec 2021
**/
class Solution {
public:
    int nthUglyNumber(int n) {
      int UG[n];
        UG[0]=1;
        int a=0, b=0, c=0, i=1;
        while(i<n){
            int x = UG[a]*2;
            int y = UG[b]*3;
            int z = UG[c]*5;
            UG[i]=min({x,y,z});
            if (UG[i]==x) a++;
            if (UG[i]==y) b++;
            if (UG[i]==z) c++;
        
            i++;
        }
        return UG[n-1];
    }
};
