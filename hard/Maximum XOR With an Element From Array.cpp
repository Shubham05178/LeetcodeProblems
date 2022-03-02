/**
* Leetcode Problem - https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
* Author - Shubham Nagaria
* Date - 2nd March 2022
**/
struct TrieNode{
    TrieNode* children[2]={NULL};
    TrieNode(){}
};
class Solution {
public:
    void insertAtTrie(TrieNode* curr, int num){
        int setbit;
        int noofbits = 31;
        while(noofbits > 0){
            noofbits--;
            setbit = 0;
            if (num & (1<<noofbits)) setbit =1;
            if(curr->children[setbit] == NULL)
                curr->children[setbit] = new TrieNode();
            curr = curr->children[setbit];
        }
    }
    int searchAtTrie(TrieNode* curr, int num){
        if(curr->children[0] == NULL && curr->children[0] == NULL) return -1; 
        int setbit;
        int nu = 0;
        int noofbits = 31;
        while(noofbits > 0){
            noofbits--;
            setbit = 0;
            if(num & (1<<noofbits)) setbit =1;
            if((setbit == 0 && curr->children[1] != NULL) || (setbit == 1 && curr->children[0] == NULL)){
                nu |= (1<< (noofbits));
                curr = curr->children[1];
            }
            else{
                curr = curr->children[0];
            }
        }
        return (nu^num);
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        TrieNode* root = new TrieNode();
        vector<vector<int>>q;
        int n = queries.size();
        vector<int>res(n);
        for(int i = 0; i < n ; i++){
            auto v = queries[i];
            q.push_back({v[1],v[0],i});
        }
        sort(q.begin(),q.end());
        sort(nums.begin(),nums.end());
        int j =0;
        int m = nums.size();
        for(auto p : q){
            int maxlimit = p[0];
            int number = p[1]; 
            int id = p[2];
            while(j< m && nums[j] <= maxlimit){
                 insertAtTrie(root,nums[j]);
                 j++;
            }
            res[id]=searchAtTrie(root,number);
        }
        return res;
    }
};
