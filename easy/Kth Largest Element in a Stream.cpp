/**
* Leetcode Problem - https://leetcode.com/problems/kth-largest-element-in-a-stream/
* Author - Shubham Nagaria
* Date - 3rd March 2022
**/
class KthLargest {
public:
    vector<int>h;
    int s;
    void bottomtoTopheapify(){
        int i = h.size()-1;
        int parent;
        while(i>0){
            parent = ((i-1)>>1);
            if(h[parent]>h[i]){
                swap(h[parent],h[i]);
                i=parent;
            }
            else
                return;
        }
    }
    void heapifytoptobottom(int i){
        int m;
        int l,r;
        while(((i<<1)+1) < s && (i<<1)+1 < h.size()){
            l = (i<<1)+1;
            r = (i<<1)+2;
            if(r<s && r<h.size())
                m = min(h[l],h[r]);
            else
                m = h[l];
            m = min(m, h[i]);
            if(m == h[i])
                return;
            else if (m == h [l]){
                swap(h[l],h[i]);
                i=l;
            }
            else{
                swap(h[r],h[i]);
                i=r;
            }
        }
    }
    int insert(int el){
        if(h.size()<s){
            h.push_back(el);
           bottomtoTopheapify();
        }
        else{
            if(h[0]< el){
                h.push_back(el);
                swap(h[0],h[h.size()-1]);
                h.pop_back();
                heapifytoptobottom(0);
            }
        }
        return h[0];
    }
    KthLargest(int k, vector<int>& nums) {
        h.clear();
        s=k;
        for (int i =0;i < s && i < nums.size();i++)
            h.push_back(nums[i]);
        
        for(int i = ((h.size())>>1)-1; i>=0; i--)
             heapifytoptobottom(i);

        for(int i = s; i < nums.size();i++)
            insert(nums[i]);
    }
    
    int add(int val) {
        return insert(val);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
