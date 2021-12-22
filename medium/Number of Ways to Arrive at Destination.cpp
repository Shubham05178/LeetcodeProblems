/**
* Leetcode Problem- https://leetcode.com/contest/biweekly-contest-59/problems/number-of-ways-to-arrive-at-destination/
* Author - Shubham Nagaria
* Date- 22nd Dec 2021
**/


#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod= 1e9+7;
        vector<pair<ll,ll>>adj[202];
        for(auto& it : roads){
            ll u=it[0];
            ll v=it[1];
            ll wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,0});
        vector<ll>distance(n),ways(n,0);
        for(int i =0; i < n;i++){
            distance[i]=922337203685477580;
        }
        ways[0]=1;
        distance[0]=1;
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            ll dis=it.first;
            ll node=it.second;
            for(auto iter: adj[node]){
                ll adjnode=iter.first;
                ll wt=iter.second;
                if((long)(wt+dis)<distance[adjnode]){
                    distance[adjnode]= dis+wt;
                    ways[adjnode]=ways[node];
                    pq.push({distance[adjnode],adjnode});
                }
                else if ((long)(wt+dis)==distance[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};
