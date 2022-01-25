/**
* Leetcode Problem - https://leetcode.com/problems/valid-mountain-array/
* Author - Shubham Nagaria
* Date - 25th Jan 2022
**/
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        int i = 0;
       while(i+1 < n && arr[i] < arr[i + 1])
             i++;
        if (i == n-1 || i == 0 ) return false;
        while(i+1 < n && arr[i] > arr[i + 1])
            i++;
        return i == n - 1;
    }
};
