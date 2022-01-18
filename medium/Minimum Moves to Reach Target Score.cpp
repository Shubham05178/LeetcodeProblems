/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-276/problems/minimum-moves-to-reach-target-score/
* Author - Shubham Nagaria
* Date - 19th Jan 2022
**/
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res=0;
        while(target > 1 && maxDoubles>0){
            res+=1+target%2;
            maxDoubles--;
            target>>=1;
        }
        return target -1 + res;
    }
};
