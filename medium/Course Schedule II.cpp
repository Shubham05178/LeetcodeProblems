/**
* Leetcode Problem - https://leetcode.com/problems/course-schedule-ii/
* Author - Shubham Nagaria
* Date - 23rd Dec 2021
**/
//O(numberCourses+ size of prerequisites array)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> Adj [numCourses];
        int indegree[numCourses];
        memset(indegree,0,sizeof(indegree));
        for(auto& i : prerequisites){
                Adj[i[1]].push_back(i[0]);
                indegree[i[0]]++;
                
        }
        
        for(int i =0; i < numCourses;i++){
            if(indegree[i]==0){
                res.push_back(i);
                indegree[i]=-1;
        }
        }
        
        int i=0;
        while(i<res.size()){
           for (int& it: Adj[res[i]]){
               indegree[it]--;
               if(indegree[it]==0)
                   res.push_back(it);
           }
                i++;
        }
            if(res.size()!= numCourses)
                return {};
            return res;
        
    }
};


