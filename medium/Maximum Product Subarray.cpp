/**
Leetcode Problem - https://leetcode.com/problems/maximum-product-subarray/
Author - Shubham Nagaria
Date - 3rd Dec 2021
**/

// Brute Force Method 
//O(N^3) time complexity and O(1) space complexity
class Solution {
  public:
    int maxProduct(vector < int > & nums) {
      int n = nums.size();
      int res = nums[0];
      for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
          int p = 1;
          for (int k = i; k <= j; k++) {
            p *= nums[k];
          }
          res = max(p, res);
        }
      }
      return res;
    }
};

// Optimal Solution 
// O(N^2) time complexity and O(1) space complexity
class Solution {
  public:
    int maxProduct(vector < int > & nums) {
      int res = nums[0];
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        int p = 1;
        for (int j = i; j < n; j++) {
          p *= nums[j];
          res = max(p, res);
        }
      }
      return res;
    }
};

// Most Optimal Solution
// O(N) time complexity and O(1) space complexity
class Solution {
  public:
    int maxProduct(vector < int > & nums) {
      int res = nums[0];
      int l = 1;
      int r = 1;
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        l *= nums[i];
        r *= nums[n - i - 1];
        res = max(res, max(l, r));
        if (l == 0) l = 1;
        if (r == 0) r = 1;
      }
      return res;
    }
};
