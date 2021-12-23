/**
Leetcode Problem - https://leetcode.com/problems/max-points-on-a-line/
Author - Shubham Nagaria
Date - 23rd Dec 2021 
**/
//Time Complexity -O(N^2)and Space Complexity - O(N)
class Solution {
public:
   int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
    int maxPoints(vector<vector<int>>& points) {
      
        int maximum=0;
        int n = points.size();
       
        for(int i =0; i < n;i++){
            int dup=0;
             map<pair<int,int>,int>count;
            for(int j =i; j <n; j++){
                int dy= points[j][1]-points[i][1];
                int dx= points[j][0]-points[i][0];
                if(dy==0 && dx==0) dup++;
                else{
                int gg=gcd(dy,dx);
                dy/=gg;
                dx/=gg;
                count[{dy,dx}]++;
                }
                
                maximum=max(count[{dy,dx}]+dup,maximum);
            }
        }
        return maximum;
    }
};
