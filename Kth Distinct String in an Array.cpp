/**
* Leetcode Problem - https://leetcode.com/problems/kth-distinct-string-in-an-array/
* Author - Shubham Nagaria
* Date - 31st Dec 2021
**/
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>freq;
        for(auto& i:arr)
          freq[i]++;
        for(auto& i:arr){
            if(freq[i]==1) k--;
            if(k==0) return i;
        }      
        return "";
    }
};
