/**
* Leetcode Problem - https://leetcode.com/problems/smallest-integer-divisible-by-k/
* Author - Shubham Nagaria
* Date - 30th Dec 2021
**/

//O(K) Time complexity O(1)space complexity
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int r=0;
        for(int i =1; i<=k ;i++){
            r=((r*10)+1)%k;
            if(r==0)
                return i;
        }
        return -1;
    }
};

// O(K) solution O(K) space complexity

class Solution {
public:
    int smallestRepunitDivByK(int k) {
       set<int>rem;
        int r=1;
        int count=1;
        while(r%k!=0){
            int n= r*10+1;
            r=n%k;
            count++;
            int prevlength=rem.size();
            rem.insert(r);
            if(rem.size()==prevlength)
                return -1;
        }
        return count;
        
    }
};
