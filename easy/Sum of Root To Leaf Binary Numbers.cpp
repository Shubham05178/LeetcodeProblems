/**
* Leetcode Problem - https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
* Author - Shubham Nagaria
* Date - 11th Jan 2022
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
    int s=0;
    void helper(TreeNode* node ,int m){
        if(node != nullptr){
            m=(m<<1)| (node ->val);
            if(node->left ==nullptr && node->right ==nullptr){
                s+=m;
        }
        helper(node->left, m);
        helper(node->right,m);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        helper(root,0);
        return s;
    }
};
