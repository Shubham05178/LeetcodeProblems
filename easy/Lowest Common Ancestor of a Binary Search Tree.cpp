/**
* Leetcode Problem - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
* Author - Shubham Nagaria
* Date - 19th Feb 2022

**/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root ->val == p->val || root->val == q->val) return root;
        if((root->val > p->val && q->val > root->val) || (p->val > root->val && q->val < root->val)) return root;
        if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right,p,q);
        return lowestCommonAncestor(root->left, p,q);
    }
};
