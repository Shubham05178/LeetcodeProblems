/**
* Leetcode Problem - https://leetcode.com/problems/maximum-number-of-balloons/
* Author - Shubham Nagaria
* Date - 31st Dec 2021
**/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>freq;
        for(char& ch : text)
            freq[ch]++;
        return min({freq['b'],freq['a'],freq['l']/2,freq['o']/2,freq['n']});
    }
};
