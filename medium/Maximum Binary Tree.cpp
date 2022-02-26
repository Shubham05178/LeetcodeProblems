/**
* Leetcode Problem - https://leetcode.com/problems/maximum-binary-tree/
* Author - Shubham Nagaria
* Date - 26th Feb 2022
**/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxIndex(vector<int>&nums,int l , int r){
        int maxi = INT_MIN,idx=-1;
        for(int i=l;i<=r;i++){
            if(maxi<nums[i]){
                maxi = nums[i];
                idx = i;
            }
        }
        return idx;
    }
    TreeNode* construct(vector<int>&nums,int l,int r){
        if(r<l) return NULL;
        int i = maxIndex(nums,l,r);
        TreeNode* node = new TreeNode(nums[i]);
        node->left = construct(nums, l,i-1);
        node->right = construct(nums,i+1,r);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int r = nums.size()-1;
        return construct(nums,0,r);
    }
};
