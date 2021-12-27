/**
* Leetcode Problem - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
* Author - Shubham Nagaria
* Date - 27th Dec 2021
**/
//O(k) time complexity O(1) space complexity
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int s=0,n= cardPoints.size();
        for(int i =0; i <k ; i++)
            s+=cardPoints[i];
            int max_=s;
        for ( int i =0; i < k;i++){
            s=s-cardPoints[k-1-i]+cardPoints[n-1-i];
            max_=max(max_,s);
        }
        return max_;
    }
};
