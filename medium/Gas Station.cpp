/**
* Leetcode Problem - https://leetcode.com/problems/gas-station/
* Author - Shubham Nagaria
* Date - 21th Jan 2022
**/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), tank =0,mi=INT_MAX,id=-1;
        for(int i =0 ; i< n ; i++)
        {
            tank += gas[i] - cost[i];
            if(mi>tank){
                mi = tank;
                id = i+1;
            }
        }
        if(tank>=0) return id%n;
        else return -1;
    }
};  
