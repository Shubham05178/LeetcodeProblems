/**
* Leetcode Problem - https://leetcode.com/problems/sum-of-two-integers/
* Author - Shubham Nagaria
* Date - 18th Dec 2021
**/

class Solution {
public:
    int getSum(int a, int b) {
       int r = a ^ b;
    unsigned carry = a & b;
    if (carry == 0){
      return r;
     } 
    else{
      return getSum(r, carry << 1);
     }  
  }
};
