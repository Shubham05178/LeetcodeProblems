/**
* Leetcode Problem - https://leetcode.com/problems/jump-game-iii/
* Author - Shubham Nagaria
* Date - 9th Dec 2021
**/
// class Solution {
// public:
//     bool canReach(vector<int>& arr, int start) {
//         int n =arr.size();
//         if(start<0 || start>=n)
//             return false;
//         if(arr[start]==0)
//             return true;
//         return canReach(arr,start+arr[start]) || canReach(arr,start-arr[start]);
//     }
// };

//Most Optimal approach Time Complexity O(N) and Space Complexity O(N) 

class Solution {
  public:
    bool canReach(vector < int > & arr, int start) {
      queue < int > q;
      q.push(start);
      int curr;
      int n = arr.size();
      while (size(q)) {
        curr = q.front();
        q.pop();
        if (arr[curr] == 0)
          return true;
         if (arr[curr] < 0) continue;
         if (curr + arr[curr] < n) q.push(curr + arr[curr]);
         if (curr - arr[curr] >= 0) q.push(curr - arr[curr]);
        arr[curr] *= -1;
      }
      return false;
    }
};
