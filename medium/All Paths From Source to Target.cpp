/**
* Leetcode Problem - https://leetcode.com/problems/all-paths-from-source-to-target/
* Author - Shubham Nagaria
* Date - 28th Nov 2021
**/
class Solution {
public:
    vector<vector<int>>res;
    void DFS(vector<vector<int>>& graph, vector<int>& added , int val){
        added.push_back(val);
        if(val==graph.size()-1 )
            res.push_back(added);
        
        for(auto neigh : graph[val])
            DFS(graph,added,neigh);
        
        added.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> added;
        DFS(graph,added,0);
        return res;
    }
};
