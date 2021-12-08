/**
* Leetcode Problem - Sort Colors
* Author - Shubham Nagaria
* Date - 8th Dec 2021
**/

// Brute Force Method
// Time Complexity- O(N log N) and space Complexity O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};


// Optimal Method (2 pass (1 pass for count sort and another for filling))
//Time Complexity-O(N) and Space Complexity O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,t=0;
        for (auto i : nums)
        {
            if(i==0)z++;
            if(i==1)o++;
            if(i==2)t++;
        }
        for(int i = 0 ; i < nums.size();i++){
            if(z!=0){
                nums[i]=0;
                z--;
                continue;
            }
            if(o!=0){
                nums[i]=1;
                o--;
                continue;
            }
            if(t!=0){
                nums[i]=2;
                t--;
                continue;
            }
        }
    }
};

//Most Optimal Method (1 pass solution)
//Time Complexity-O(N) and Space Complexity O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
    int mid=0, left=0, right=nums.size()-1;
        while(mid<=right){
            switch(nums[mid]){
                case 0 :
                    swap(nums[mid++],nums[left++]);
                    break;
                case 1 :
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[right--]);
                    break;
            }
        }
    }
 };
