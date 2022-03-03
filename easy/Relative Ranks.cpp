/**
* Leetcode Problem - https://leetcode.com/problems/relative-ranks/
* Author - Shubham Nagaria
* Date - 4th March 2022
**/
class Solution {
public:
    string RankGiver(int i){
        if(i==1) return "Gold Medal";
        if(i==2) return "Silver Medal";
        if(i==3) return "Bronze Medal";
        return to_string(i);
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int>mp;
        int n = score.size();
        priority_queue<int>pq;
        for(int i =0; i < n;i++){
            mp[score[i]]=i;
            pq.push(score[i]);
        }
        vector<string>res(n);
        int i = 1;
        while(!pq.empty()){
            res[mp[pq.top()]]=RankGiver(i);
            i++;
            pq.pop();
        }
        return res;
    }
};
