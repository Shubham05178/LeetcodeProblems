/**
* Leetcode Problem - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
* Author - Shubham Nagaria
* Date - 12th Feb 2022
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
    TreeNode* construct(vector<int>& inorder, int ins, int ine, vector<int>& postorder,int pos, int poe, unordered_map<int,int>&mp){
        if(poe < pos) return NULL;
        TreeNode* node = new TreeNode(postorder[poe]);
        int x = mp[postorder[poe]]-ins;
        node->left = construct(inorder,ins, mp[postorder[poe]]-1 , postorder,pos,pos+x-1,mp);
        node->right = construct(inorder,mp[postorder[poe]]+1, ine,postorder,pos+x, poe-1,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size()-1;
        unordered_map<int,int>mp;
        for(int i =0; i <= len; i++)
            mp[inorder[i]]=i;
        return construct(inorder,0,len,postorder,0,len,mp);
    }
};
