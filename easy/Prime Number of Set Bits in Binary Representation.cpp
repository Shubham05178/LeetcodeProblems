/**
* Leetcode Problem- https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
* Author - Shubham Nagaria  
* Date - 20th Dec 2021
**/

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        bool prime[32];
        memset(prime, true,sizeof(prime));
        prime[0]=prime[1]=false;
        for(int i =2; i*i < 32; i++){
            if(prime[i]){
            for(int j =i*i; j < 32; j+=i){
            prime[j]=false;   
            }
            }
        }
        int count =0,ct=0;
        for(int i = left;i<=right;i++){
            int x=i;
            ct=0;
            while(x){
                ct++;
                x&=(x-1);
            }
            if(prime[ct])
                count++;
        }
        
        return count;
        
    }
};
