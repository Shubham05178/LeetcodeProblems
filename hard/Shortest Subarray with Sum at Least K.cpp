/**
* Leetcode Problem - https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
* Author- Shubham Nagaria
* Date - 30th Nov 2021 
**/
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int minn=INT_MAX;
        int n = nums.size();
        deque<int>deq;
        vector<long long int >pre(n+1,0);
        
        for(int i =0; i<n;i++){
         pre[i+1]=pre[i]+nums[i];
        }
        for(int i=0;i<=n;i++){
            while(!deq.empty() &&pre[i]- pre[deq.front()]>=k){
                minn=min(minn,i-deq.front());
                deq.pop_front();
                
            }
            while(!deq.empty() && pre[i]<pre[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(i);
        }
        return  minn!=INT_MAX ? minn:-1;
    }
};
