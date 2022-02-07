/**
* Leetcode Problem - https://leetcode.com/problems/sliding-window-maximum/
* Author - Shubham Nagaria
* Date - 7th Feb 2022
**/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>deq;
        vector<int>res;
        int i =0 , n = nums.size();
        while(i<n){
            while(deq.size() !=0 &&  deq.back()<nums[i])
                deq.pop_back();
            deq.push_back(nums[i]);
            if(i>=k-1){
                res.push_back(deq.front());
                if(deq.front()== nums[i+1-k])
                    deq.pop_front();
            }
            i++;
        }
        return res;
    }
};
