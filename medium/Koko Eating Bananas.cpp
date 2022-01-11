/**
* Leetcode Problem - https://leetcode.com/problems/koko-eating-bananas/ 
* Author - Shubham Nagaria
* Date - 11th Jan 2022
**/
class Solution {
public:
    int check(vector<int>&piles,int mid){
        int time=0;
        for(int i: piles)
            time+= i%mid==0? i/mid : (i/mid)+1;
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low= 1;
        int high=low;
        for(int i:piles)
            high=max(high,i);
        int mid,timereq,ans;
        while(low<=high){
            mid = low+ ((high-low)>>1);
            timereq=check(piles,mid);
            if(timereq<=h) ans =mid,high=mid-1;
            else low=mid+1;     
        }
        return ans;
    }
};
