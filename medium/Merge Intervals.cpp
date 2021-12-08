/**
* Leetcode Problem - https://leetcode.com/problems/merge-intervals/
* Author - Shubham Nagaria
* Date - 28th Oct 2021
**/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(int i=0;i<n; i++){
            if(intervals[i][0]<=res.back()[1]){
                if(intervals[i][1]>res.back()[1]){
                    res.back()[1]=intervals[i][1];
                }
            }
            else{
                res.push_back(intervals[i]);
            }
            
        }
        return res;
    }
};
/**
* Leetcode Problem - https://leetcode.com/problems/merge-intervals/
* Author - Shubham Nagaria
* Date - 8th Dec 2021
Merge Intervals.cpp
**/
//Most optimal Approach -1
// Time Complexity - O(N log N) and Space Complexity -O(N)
class Solution {
  public:
    vector < vector < int >> merge(vector < vector < int >> & intervals) {
      vector < vector < int >> mergeIntervals;
      if (intervals.size() == 0)
        return mergeIntervals;
      sort(intervals.begin(), intervals.end());
      vector < int > tempInterval = intervals[0];
      for (auto it: intervals) {
        if (it[0] <= tempInterval[1]) {
          tempInterval[1] = max(it[1], tempInterval[1]);
        } else {
          mergeIntervals.push_back(tempInterval);
          tempInterval = it;
        }
      }
      mergeIntervals.push_back(tempInterval);
      return mergeIntervals;
    }
};

// Most Optimal Approach -2 
// Time Complexity - O(N log N) Space Complexity O(N)
class Solution {
  public:
    vector < vector < int >> merge(vector < vector < int >> & intervals) {
      vector < vector < int >> mergeIntervals;
      sort(intervals.begin(), intervals.end());
      for (auto it: intervals) {
        if (mergeIntervals.empty() || mergeIntervals.back()[1] < it[0])
          mergeIntervals.push_back(it);
        else
          mergeIntervals.back()[1] = max(mergeIntervals.back()[1], it[1]);
      }
        return mergeIntervals;
    }
};
