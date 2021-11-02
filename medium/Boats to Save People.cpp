/**
* Leetcode problem - https://leetcode.com/problems/boats-to-save-people
* Author - Shubham Nagaria
* Date - 2nd Nov 2021
**/

class Solution {
  public:
    int numRescueBoats(vector < int > & people, int limit) {
      sort(people.begin(), people.end());
      int i = 0, j = people.size() - 1, ans = 0;
      while (i <= j) {
        ans++;
        if (people[i] + people[j] <= limit)
          i++;
        j--;
      }
      return ans;
    }
};
