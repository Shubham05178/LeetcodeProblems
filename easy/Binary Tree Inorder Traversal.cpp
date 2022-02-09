/**
* Leetcode Problem - https://leetcode.com/problems/binary-tree-inorder-traversal/
* Author - Shubham Nagaria
* Date - 9th Feb 2022
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
    void inorder(vector<int> &arr, TreeNode *node){
        if( node == NULL ) return;
        inorder(arr,node->left);
        arr.push_back(node->val);
        inorder(arr, node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>arr;
        inorder(arr,root); 
        return arr;
    }
};
