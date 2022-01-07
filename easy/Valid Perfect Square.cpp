/**
* Leetcode Problem - https://leetcode.com/problems/valid-perfect-square/
* Author - Shubham Nagaria
* Date - 7th Jan 2022
**/
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int l=1, h=num, mid,ans,m;
        while(l<=h){
            mid = l + ((h-l)>>1);
            m= mid*mid;
            if(m== num){
                ans=mid;
                break;
            }
            else if(m<num) ans = mid ,l=mid+1;
            else h =mid-1;
        }
    return (ans*ans) == num;
    }
};
