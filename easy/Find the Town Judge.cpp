x/**
* Leetcode Problem - https://leetcode.com/problems/find-the-town-judge/
* Author - Shubham Nagaria
* Date - 3rd Jan 2022
**/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int arr[n+1];
        memset(arr,0,sizeof(arr));
        for(auto &i : trust)
            arr[i[0]]--,arr[i[1]]++;
      
       for(int i =1; i < n+1;i++)
           if(arr[i]==n-1) return i;
        
        return -1;
    }
};
