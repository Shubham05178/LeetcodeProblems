/**
* Leetcode Problem - https://leetcode.com/problems/minimum-number-of-refueling-stops/
* Author - Shubham Nagaria
* Date - 6th March 2022
**/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>maxHeap;
        int dis=startFuel, k=0;
        sort(stations.begin(),stations.end());
        int i = 0;
        while(true){
            while(i<stations.size() && stations[i][0] <= dis)
                maxHeap.push(stations[i++][1]);
            if(dis>=target) return k;
            if(dis<target && maxHeap.size()==0)
                return -1;
            dis+=maxHeap.top();
            maxHeap.pop();
            k++;
        }
        return k;
    }
};
