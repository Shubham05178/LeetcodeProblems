/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-271/problems/rings-and-rods/
* Author - Shubham Nagaria
* Date - 30th Dec 2021
**/
class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        vector<set<char>>rods(10);
        int ind;
        for( int i = 1; i < n; i+=2){
            ind=rings[i]-'0';
            rods[ind].insert(rings[i-1]);
        }
        int c=0;
        for( int i =0; i < 10; i++){
            if(rods[i].size()==3)
                c++;
        }
    return c;
    }

};
