/**
* Leetcode Problem - https://leetcode.com/problems/merge-sorted-array/
* Author - Shubham Nagaria
* Date - 11th Jan 2022
**/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int N = m+n-1;
        m=m-1;
        n=n-1;
        
        for(int i = N; i >=0; i--){
            if(m>=0 && n>=0){
                if(nums1[m]<nums2[n]) nums1[i]= nums2[n--];
                else nums1[i]=nums1[m--];
            }
            else if (n>=0){
                nums1[i]= nums2[n--];
            }
            else return;
        }
    }
};
