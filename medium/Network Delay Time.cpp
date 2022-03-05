/**
* Leetcode Problem - https://leetcode.com/problems/network-delay-time/
* Author - Shubham Nagaria
* Date - 5th March 2022
**/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>>graph(n+1);
        vector<bool>visited(n+1,false);
        for(auto i: times)
            graph[i[0]].push_back({i[2],i[1]});
        pq.push({0,k});
        int res= 0, count=0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            if(visited[top.second])
                continue;
            res = max(res, top.first);
            count++;
            visited[top.second]=true;
            for(auto l: graph[top.second])
                pq.push({top.first+l.first, l.second});
        }
        return count==n ? res:-1;
    }
};
