/**
* Leetcode Problem - https://leetcode.com/problems/sum-of-subarray-ranges/
* Author - Shubham Nagaria
* Date - 30th Dec 2021
**/
// O(N) time complexity && O(N) space complexity
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans =0;
        int i =0;
        int n = nums.size();
        int j,k;
        stack<int>s;
        for(int i =0; i<=n; i++){
            while(!s.empty() && nums[s.top()]>(i==n ? -1e9-10:nums[i])){
                j= s.top();
                s.pop();
                k= s.empty()? -1:s.top();
                ans-= (long)nums[j]*(i-j)*(j-k);
            }
            s.push(i);
        }
        s=stack<int>();
        for(int i=0; i <=n;i++){
            while(!s.empty() && nums[s.top()]< (i==n? 1e+10:nums[i])){
                j= s.top();
                s.pop();
                k=s.empty()? -1:s.top();
                ans+= (long)nums[j]*(i-j)*(j-k);
            }
            s.push(i);
        }
        return ans;
    }
};
