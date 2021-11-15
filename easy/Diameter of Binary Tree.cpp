/**
* Leetcode Problem -https://leetcode.com/problems/diameter-of-binary-tree
* Author - Shubham Nagaria
* Date - 16th nov 2021
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
    int solve(TreeNode* node, int& res){
        if(node==nullptr)
            return 0;
        int l =solve(node->left,res);
        int r= solve(node->right,res);
        res=max(res,l+r);
        return 1+max(l,r);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res= INT_MIN;
        solve(root,res);
        return res;
        
    }
};
