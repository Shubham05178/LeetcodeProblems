/**
* Leetcode Problem - https://leetcode.com/problems/last-stone-weight/
* Author - Shubham Nagaria
* Date - 6th March 2022
**/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxHeap;
        for(int i : stones)
            maxHeap.push(i);
        int m, n;
        while(maxHeap.size()>1){
            m =maxHeap.top();
            maxHeap.pop();
            n = maxHeap.top();
            maxHeap.pop();
            if(m-n)
                maxHeap.push(m-n);
           
        }
        return maxHeap.size() ? maxHeap.top() : 0;
    }
};
