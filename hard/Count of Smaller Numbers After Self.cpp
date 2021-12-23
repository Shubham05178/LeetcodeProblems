/**
* Leetcode Problem - https://leetcode.com/problems/count-of-smaller-numbers-after-self/
* Author - Shubham Nagaria
* Date - 24th Dec 2021
**/

//O(n log n) time complexity and O(n) space complexity
class Solution {
public:
    void merge(vector<int> &count, vector<pair<int, int> > &pairs, int left, int mid, int right) {
        vector<pair<int, int> > tmp(right-left+1);
        int i = left, j = mid+1, k = 0;
        while (i <= mid && j <= right) {
            if (pairs[i].first <= pairs[j].first)
                tmp[k++] = pairs[j++];
            else{
                count[pairs[i].second] += right - j + 1;
                tmp[k++] = pairs[i++];
            } }
        while (i <= mid)   tmp[k++] = pairs[i++];
        while (j <= right) tmp[k++] = pairs[j++];
        for (int i = left; i <= right; i++) pairs[i] = tmp[i-left];
    }        
    void divideForMerge(vector<int> &count, vector<pair<int, int> > &pairs, int left, int right) {
        if (left == right) return;
        int mid = left + (right-left)/2;
        divideForMerge(count, pairs, left, mid);
        divideForMerge(count, pairs, mid+1, right);
        merge(count, pairs, left, mid, right);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, int> > pairs(n);
        for (int i = 0; i < n; i++) pairs[i] = make_pair(nums[i], i);
        vector<int> count(n, 0);
        divideForMerge(count, pairs, 0, n-1);
        return count;
    }
};
