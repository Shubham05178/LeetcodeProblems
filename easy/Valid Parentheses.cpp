/**
* Leetcode Problem- https://leetcode.com/problems/valid-parentheses/
* Author - Shubham Nagaria
* Date - 2nd Dec 2021
**/

class Solution {
  public:
    bool isValid(string s) {
      vector < char > p;
      int n;
      for (auto i: s) {
        if (i == '(' || i == '{' || i == '[')
          p.push_back(i);
        else if (i == '}') {
          n = p.size();
          if (n == 0 || '{' != p[n - 1])
            return false;
          p.pop_back();
        } else if (i == ']') {
          n = p.size();
          if (n == 0 || '[' != p[n - 1])
            return false;
          p.pop_back();
        } else if (i == ')') {
          n = p.size();
          if (n == 0 || '(' != p[n - 1])
            return false;
          p.pop_back();
        }
      }
      if (p.size() > 0) return false;
      return true;
    }
};
