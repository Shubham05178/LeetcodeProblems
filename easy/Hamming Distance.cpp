/**
*   Leetcode Problem- https://leetcode.com/problems/hamming-distance/
*  Author - Shubham Nagaria
*   Date- 19th Nov 2021

**/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int c =0;
        while( x || y){
            if(x%2!=y%2)
                c++;
            x=int(x/2);
            y=int(y/2);
            
        }
        return c;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        int c =0;
        for(int i =0 ; i<32;i++){
            c+=(x>>i &1)!=(y>>i &1);
        }
        return c;
    }
};
