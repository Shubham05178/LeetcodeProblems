/**
* Leetcode Problem - https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
* Author - Shubham Nagaria
* Date - 18th Dec 2021
**/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
    vector<vector<int>>c(14);
    for(int & i : arr){
        int cc=0,x=i;
        while(i){
            i=i&(i-1);
            cc++;
        }
        c[cc].push_back(x);
    }
        vector<int> res;
        for(int i =0; i <14; i++){
            sort(c[i].begin(),c[i].end());
          res.insert(res.end(), c[i].begin(), c[i].end());
        }
        return res;
    }
};

class Solution {
public:
   static int count(int x){
        int c=0;
        while(x){
            x&=(x-1);
            c++;
        }
        return c;
    }
    static bool comp(int x, int y){
        int c1=count(x);
        int c2=count(y);
        if(c1==c2)
            return x<y;
        return c1<c2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};

class Solution {
public:
    
    static bool compare(const int& a, const int& b){
        int c1 = __builtin_popcount(a);
        int c2 = __builtin_popcount(b);
        if(c1 == c2)
            return a < b;
        return c1 < c2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        std::sort(arr.begin(),arr.end(), compare);
        return arr;
    }
};
