/**
* Leetcode Problem - https://leetcode.com/problems/kth-largest-element-in-an-array/
* Author - Shubham Nagaria
* Date - 4th March 2022
**/
class Solution {
public:
    void Heapify(vector<int>& H ,int i){
        int l,r ,m;
        while((i<<1)+1<H.size()){
            l = (i<<1)+1;
            r = (i<<1)+2;
            if(r < H.size()) m = min(H[l],H[r]);
            else m = H[l];
            m = min(m , H[i]);
            if(H[i]== m)
                return;
            else if (H[l]== m){
                swap(H[l],H[i]);
                i=l;
            }
            else{
                swap(H[r],H[i]);
                i=r;
            }
        }
    }
    void insert(vector<int>&H, int element){
        if(element > H[0]){
            H[0] = element;
           Heapify(H,0);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        vector<int>n(nums.begin(),nums.begin()+k);
        int i = (n.size()>>1)-1;
        while(i>=0)
            Heapify(n,i--);
        for(i = k; i < nums.size();i++)
           insert(n,nums[i]);
        return n[0];
    }
};
