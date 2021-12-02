/**
Leetcode Problem - https://leetcode.com/problems/find-the-duplicate-number/
Author - Shubham Nagaria
Date - 3rd Dec 2021
day1-Find the Duplicate Number.cpp
**/

// Brute force Method:

//O(NlogN) time complexity and O(1) space complexity

class Solution {
  public:
    int findDuplicate(vector < int > & nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1])
          return nums[i];
      }
      return 0;
    }
};

// Optimal Method :

// O(N) time complexity and O(N) space complexity
class Solution {
  public:
    int findDuplicate(vector < int > & nums) {
      vector < int > count(nums.size() + 1, 0);
      for (auto i: nums) {
        if (count[i] != 0)
          return i;
        count[i] = 1;
      }
      return 0;
    }
};
// Most Optimal Method:

// O(N) time complexity and O(1) space complexity 
class Solution {
  public:
    int findDuplicate(vector < int > & nums) {
      int fast = nums[0];
      int slow = nums[0];
      do {
        fast = nums[nums[fast]];
        slow = nums[slow];
      } while (slow != fast);
      fast = nums[0];
      while (fast != slow) {
        fast = nums[fast];
        slow = nums[slow];
      }
      return slow;

    }
};
