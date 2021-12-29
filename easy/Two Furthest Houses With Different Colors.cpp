/**
* Leetcode Problem - https://leetcode.com/problems/two-furthest-houses-with-different-colors/
* Author - Shubham Nagaria
* Date - 30th Dec 2021
**/
// O(N) Time complexity and O(1) space complexity 
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size()-1;
        int i =0,j =n;
        while(colors[0]==colors[j])j--;
        while(colors[n]==colors[i])i++;
        
    return max(j,n-i);
    }
};
//O(N^2) Time complexity and O(1) space Complexity
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size()-1;
        int max_=INT_MIN;
        for(int i =0 ; i <= n; i++){
            for(int j =n; j >i; j --){
                if(colors[i]!=colors[j])
                max_=max(max_,abs(i-j));
            }
        }
    return max_;
    }
};
