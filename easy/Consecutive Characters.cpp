/**
* Leetcode Problem - https://leetcode.com/problems/consecutive-characters/
* Author - Shubham Nagaria
* Date - 13th Dec 2021
**/


//Bruteforce Method - time complexity - O(N^2) and space complexity O(1)
class Solution {
public:
    int maxPower(string s) {
        int m=1;
        int count=1;
        int n =s.size();
        for(int i =0 ; i <n; i++ ){
            count=1;
            char c=s[i];
            for(int j=i+1;j<n ; j++){
                if(c==s[j]){
                    count++;
                }
                else
                    break;
            }
            if(m<count)
                m=count;
            
        }
        return m; 
    }
};


//Most Optimal Solution - one pass solution O(N) time complexity, O(1)space complexity
class Solution {
public:
    int maxPower(string s) {
        int count =1;
        int m =1;
        for(int i =1; i <s.size();i++){
            if(s[i]==s[i-1]) count++;
            else count=1;
            if (m<count)
                m=count;
        }
     return m;   
    } 
};
