/**
* Leetcode Problem - https://leetcode.com/problems/decode-xored-array/
* Author - Shubham Nagaria
* Date - 18th Dec 2021
**/

// O(N) time complexity O(1) space complexity
class Solution {
    public:
        vector < int > decode(vector < int > & encoded, int first) {
            vector < int > res;
            res.push_back(first);
            for (auto i: encoded) {
                first ^= i;
                res.push_back(first);
            }
            return res;

        }
};

// O(N) time complexity O(1) space complexity
class Solution {
    public:
        vector < int > decode(vector < int > & encoded, int first) {
            vector < int > res = { first  };
            for (int & a: encoded)
                res.push_back(first ^= a);
            return res;
        }
