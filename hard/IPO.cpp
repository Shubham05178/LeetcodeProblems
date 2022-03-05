/**
* Leetcode Problem - https://leetcode.com/problems/ipo/
* Author - Shubham Nagaria
* Date - 6th March 2022
**/
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>cp;
        priority_queue<int>maxHeap;
        int i = 0, N = profits.size();
        for(i=0; i < profits.size();i++)
          cp.push_back({capital[i], profits[i]});
        i = 0;
        sort(cp.begin(),cp.end());
        while(k--){
            while( i < N && cp[i].first <= w){
                maxHeap.push(cp[i].second);
                i++;
            }
            if(maxHeap.size()>0){
                w+=maxHeap.top();
                maxHeap.pop();
            }
        }
        return w;
    }
};
