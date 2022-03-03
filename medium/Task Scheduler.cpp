/**
* Leetcode Problem - https://leetcode.com/problems/task-scheduler/
* Author - Shubham Nagaria
* Date - 4th March 2022
**/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>count;
        priority_queue<int>pq;
        for(char ch : tasks) count[ch]++;
        for(auto i : count) pq.push(i.second);
        int time = 0, ex;
        vector<int>exec;
        while(!pq.empty()){
            exec.clear();
            ex = 0;
            for(int i = 0; i <= n;i++){
                if(!pq.empty()){
                    exec.push_back(pq.top() - 1);
                    pq.pop();
                    ex++;
                }
            }
            for(int i : exec)
                if(i != 0) pq.push(i);
                
            time += pq.empty() ? ex : (n + 1);
        }
        return time;
    }
};
