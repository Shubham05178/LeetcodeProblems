/**
* Leetcode Problem - https://leetcode.com/problems/can-place-flowers/
* Author - Shubham Nagaria
* Date - 18th Jan 2022
**/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int j =n;
        int N = flowerbed.size();
        for(int i =0;i<N; i++ )
        {
            if(flowerbed[i]==0 && (i==N-1 || flowerbed[i+1]==0) && (i==0 || flowerbed[i-1]==0))
            {
                j--;
                flowerbed[i++]=1;
                if (j<=0) return true;
            }
        }
         return j<=0;      
    }
};
