/**
* Leetcode Problem - https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
* Author - Shubham Nagaria
* Date - 2nd Jan 2022
**/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> c(60);
        int res = 0;
        for (int t : time) {
            res += c[(540 - t) % 60];
            c[t % 60] += 1;
        }
        return res;
    }
};
