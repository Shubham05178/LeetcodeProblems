/**
* Leetcode Problem - https://leetcode.com/problems/split-array-largest-sum/
* Author - Shubham Nagaria
* Date - 9th Jan 2022
**/
#define ll long long int
class Solution {
public:
    bool check(vector<int>& nums, int m, ll mid, int N){
        ll currsum =nums[0];
        int currdiv=1;
        for(int i =1; i < N; i++){
            if(currsum+nums[i]<=mid)
                currsum+=nums[i];
            else{
                currsum=nums[i];
                currdiv++;
            }
        }
        return currdiv<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int low =0;
        ll high =0;
        for(int& i : nums)
            low= max(low, i), high+=i;
        int N = nums.size();
        ll mid, ans;
        while(low<=high){
            mid = low+((high - low)>>1);
            if(check(nums, m ,mid,N)){
                ans =mid;
                high = mid-1;
            }
            else
                low= mid+1;
        }
        return ans;
    }
};
