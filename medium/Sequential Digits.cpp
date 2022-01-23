/**
* Leetcode Problem - https://leetcode.com/problems/sequential-digits/
* Author - Shubham Nagaria
* Date - 23rd Jan 2022
**/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>res;
   for(int i =1; i<10; i++){
       int N= i;
       for(int j =i+1; j <10;j++){
           N=N*10+j;
           if(N>=low &&  N<=high)
               res.push_back(N);
            }
        }     
    sort(res.begin(),res.end());
    return res;
    }
};
