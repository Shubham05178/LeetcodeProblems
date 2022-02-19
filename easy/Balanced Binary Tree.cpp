/**
* Leetcode Problem - https://leetcode.com/problems/balanced-binary-tree/
* Author - Shubham Nagaria
* Date - 20th Feb 2022
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
    pair<bool,int>Traverse(TreeNode* root){
        if(root == NULL) return {true,0};
        auto l = Traverse(root->left);
        auto r = Traverse(root->right);
        return make_pair(l.first && r.first && abs( l.second - r.second) < 2, max(l.second,r.second)+1); 
    }
    bool isBalanced(TreeNode* root) {
       return Traverse(root).first;
    }
};
