/**
* Leetcode Problem - https://leetcode.com/problems/largest-number-at-least-twice-of-others/
* Author - Shubham Nagaria
* Date - 1st Jan 2022
**/
//two pass solution 
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ma =INT_MIN, n= nums.size(),id;
        for(int i=0;i<n;i++){
            if(nums[i]>ma){
                id=i;
                ma=nums[i];
            }
        }
        for(int i =0; i < n ; i++){
            if(id!=i && (nums[i] <<1) > nums[id])
                return -1;
        }
        return id;
    }
};

//one pass solution
class Solution {
public:
int dominantIndex(vector<int>& nums) {
    int max1 = 0, max2 = 0, idxOfMax1 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > max1) {
            max2 = max1;
            max1 = nums[i];
            idxOfMax1 = i;
        } else if (nums[i] > max2) {
            max2 = nums[i];
        }
    }        
    return max1 >= max2 * 2 ? idxOfMax1 : -1;
}
};

