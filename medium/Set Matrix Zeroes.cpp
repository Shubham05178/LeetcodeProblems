/**
* Leetcode Problem - https://leetcode.com/problems/set-matrix-zeroes/
* Author - Shubham Nagaria
* Date - 8th Dec 2021
**/
// Optimal Way - Time Complexity O(N*M) and Space Complexity - O(N+M)
class Solution {
  public:
    void setZeroes(vector < vector < int >> & matrix) {
      int n = matrix.size(), m = matrix[0].size();
      vector < int > dummyrow(n, 1), dummycolumn(m, 1);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (matrix[i][j] == 0) {
            dummyrow[i] = 0;
            dummycolumn[j] = 0;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (dummyrow[i] == 0 || dummycolumn[j] == 0)
            matrix[i][j] = 0;
        }
      }
    }
};
//Most Optimal Way 
//Time Complexity -O(N*M) and Space Complexity -O(1)
class Solution {
  public:
    void setZeroes(vector < vector < int >> & matrix) {
      bool isCol = false;
      int n = matrix.size(), m = matrix[0].size();
      for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0)
          isCol = true;
        for (int j = 1; j < m; j++) {
          if (matrix[i][j] == 0) {
            matrix[0][j] = 0;
            matrix[i][0] = 0;
          }
        }
      }
      for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
          if (matrix[i][0] == 0 || matrix[0][j] == 0)
            matrix[i][j] = 0;
        }
      }
      if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++)
          matrix[0][j] = 0;
      }
      if (isCol) {
        for (int i = 0; i < n; i++)
          matrix[i][0] = 0;
      }
    }
};
