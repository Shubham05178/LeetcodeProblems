/**
* Leetcode Problem - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
* Author - Shubham Nagaria
* Date - 9th Jan 2022
**/
#define ll long long int
class Solution {
public:
    bool check(vector<int>& weights,ll mid, int availabledays, int N){
        int currdays=1;
        ll totalweight= weights[0];
        for(int i =1; i < N; i++){
            if(totalweight+weights[i]<= mid)
              totalweight+=weights[i];
            else{
                currdays++;
                totalweight= weights[i];
            }
        }
        return currdays<=availabledays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        ll high =0; int low=0;
        for(int &i:weights)
        {
            high += i;
            low= max(i,low);
        }
        ll ans,mid;
        int N = weights.size();
        while(low<= high){
            mid = low+ ((high - low)>>1);
            if(check(weights,mid,days,N)){
                ans=mid;
                high = mid-1;
            }
            else
                low= mid+1;
        }
        return ans;
    }
};
