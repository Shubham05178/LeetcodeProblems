/**
* Leetcode Problem - https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
    void traverse(TreeNode* root, int& x){
       if (root == NULL) return;
        traverse(root->left,x);
        int c= root->val;
        root->val = x;
        x-= c;
        traverse(root->right,x);
    }
    int sumTree(TreeNode* root){
        if(root == NULL) return 0;
        return root->val+sumTree(root->left)+sumTree(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int x = sumTree(root);
        traverse(root,x);
        return root;
    }
};
