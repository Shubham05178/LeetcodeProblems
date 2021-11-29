/**
* Leetcode Problem- https://leetcode.com/problems/subarray-sum-equals-k/
* Author - Shubham Nagaria
* Date - 29th Nov 2021
**/
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> table = {{0,1}};
    int answer = 0, s = 0;
    
    for(auto &x: nums){
        s += x;
      if(table.count( s - k) ) {
          answer += table[s-k];
      }
        table[s]++;        
    }
    
    return answer;
  }
};
