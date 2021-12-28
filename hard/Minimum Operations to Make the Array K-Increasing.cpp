/**
* Leetcode Problem - https://leetcode.com/contest/weekly-contest-272/problems/minimum-operations-to-make-the-array-k-increasing/
* Author - Shubham Nagaria
* Date - 28th Dec 2021
**/
// Time complexity O(K * N/K * log(N/K)) = O(N * log(N/K))
// Space Complexity O(N/K)
class Solution {
public:
    int lengthOfLongestNonDecreasingSubsequence(vector<int>& arr1){
        vector<int>sub;
        for(int i=0; i <arr1.size();i++){
            int x= arr1[i];
            if(sub.empty() ||sub[sub.size()-1]<=x)
                sub.push_back(x);
            else{
                int idx= upper_bound(sub.begin(),sub.end(),x)-sub.begin();
                sub[idx]=x;
            }
        }
        return sub.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans=0;
        for(int i = 0; i<k ; i++){
            vector<int> newArray;
            for(int j =i ; j <n ; j+=k)
                newArray.push_back(arr[j]);
            ans+=newArray.size()-lengthOfLongestNonDecreasingSubsequence(newArray);
        }
        return ans;
    }
};
