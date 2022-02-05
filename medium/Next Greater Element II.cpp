/**
* Leetcode Problem - https://leetcode.com/problems/next-greater-element-ii/
* Author - Shubham Nagaria
* Date - 6th Feb 2022
**/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nums1=nums;
        int m = nums.size();
        vector<int>res(m,0);
        nums1.insert(nums1.end(),nums.begin(),nums.end());
        stack<int>st;
        int n = nums1.size();
        for(int i = n -1;i>=0;i--){
            while(!st.empty() && st.top() <= nums1[i])
                st.pop();
            if(st.empty() && i< m) res[i]= -1;
            else if (i<m) res[i]= st.top();
            st.push(nums1[i]);
        }   
        return res;
    }
};
