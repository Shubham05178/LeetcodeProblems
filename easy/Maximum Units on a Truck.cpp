/**
* Leetcode Problem - https://leetcode.com/problems/maximum-units-on-a-truck/
* Author - Shubham Nagaria
* Date - 27th Dec 2021
**/
//sort using function.
// O(N log N) time complexity O(1) space.
class Solution {
public:
    static bool comp(vector<int > a, vector<int>b){
        return a[1]>=b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int i =0;
        int c=0;
        int n = boxTypes.size();
        while(truckSize && i < n){
            if (truckSize>=boxTypes[i][0]){
                truckSize-=boxTypes[i][0];
                c+=boxTypes[i][0]*boxTypes[i][1];
                i++;
            }
            else{
                c+=truckSize*boxTypes[i][1];
                truckSize=0;
                break;
            }
        }
        return c;
    }
};



//Most Optimal Solution
//bucket sort 
//O(N) time complexity and space complexity -O(1)

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    vector<int> box(1001,0);
        for(auto & i : boxTypes)
            box[i[1]]+=i[0];
        int rem = truckSize;
        int c=0;
        int i =1000;
        while(i>=0){
            if(box[i]==0) i--;
            else{
                if(box[i]<rem){
                    c+=box[i]*i;
                    rem-= box[i];
                   i--;
                }
                else{
                    c+=rem*i;
                    return c;
                }
            }
        }
        return c;
    }
};
