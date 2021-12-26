 /**
 * Leetcode Problem - https://leetcode.com/problems/height-checker/
 * Author - Shubham Nagaria
 * Date - 27th Dec 2021
 **/

//working correct O(N) using countsort using O(N) space.
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        map<int,int> count;
        for( auto & i: heights)
            count[i]++;
        int n = heights.size();
        int j =1;
        int c=0;
        for(int i =0 ; i < n; i++){
            while(count[j]==0) j++;
            if (j !=heights[i])c++;
             count[j]--;
        }
        return c;
    }
};

// Time complexity O(N) using space O(1)
// failing for test case for ex. [1,1,4,1,2,5,6].

// class Solution {
// public:
//     int heightChecker(vector<int>& heights) {
//         int n = heights.size();
//         int c=0;
//         int m =heights[0];
//         for(int i =1;i < n; i++){
//             if(m<=heights[i]) m=heights[i];
//             if(m>heights[i]) c++;
//         }
//         return c;
//     }
// };
