/**
Leetcode Problem - https://leetcode.com/contest/biweekly-contest-59/problems/minimum-time-to-type-word-using-special-typewriter/
Author - Shubham Nagaria
Date - 22nd Dec 2021
**/
class Solution {
public:
    int minTimeToType(string word) {
        int time=word.size();
        char prev='a';
        for(char c:word){
            if(c>=prev)
                time+=min(c-prev,25-c+prev+1);
            else
                time+= min(prev-c,25-prev+c+1);
            prev=c;
        }
    return time;
    }
};

class Solution {
public:
    int minTimeToType(string word) {
        int time=word.size();
        char prev='a';
        for(char c:word){
            time+=min(abs(c-prev),min(25-c+prev,25-prev+c)+1);
            prev=c;
        }
    return time;
    }
};
