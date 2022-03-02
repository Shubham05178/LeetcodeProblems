/**
* Leetcode Problem - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
* Author - Shubham Nagaria
* Date - 2nd March 2022
**/
struct TrieNode{
    TrieNode* children[2]={NULL};
    TrieNode(){}
};
class Solution {
public:
    void insertInTrie(TrieNode* root, int num, int& maximum){
        TrieNode* curr = root;
        int setbit, noofbits =32;
        if(curr->children[0]==NULL && curr->children[1]==NULL){
            while(noofbits--){
                setbit =0;
                if( num & (1<<noofbits)) setbit = 1;
                if(curr->children[setbit]==NULL)
                    curr->children[setbit] = new TrieNode();
                curr = curr->children[setbit];
            }
            maximum = 0;
        }
        else{
            TrieNode* curr1 = root;
            int nu = 0;
            while(noofbits--){
                setbit = 0;
                if(num & (1<<noofbits)) setbit =1;
                if((setbit == 0 && curr1->children[1]!=NULL ) || (setbit == 1 && curr1->children[0]==NULL)){
                    nu |= (1<<noofbits);
                    curr1 = curr1->children[1];
                }
                else 
                    curr1 = curr1->children[0];
                if(curr->children[setbit]==NULL)
                    curr->children[setbit] = new TrieNode();
                curr = curr->children[setbit];
            }
        maximum = max(maximum, (nu^num));
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int maximum = 0;
        for(int i : nums)
            insertInTrie(root,i,maximum);
       return maximum;
    }
};
