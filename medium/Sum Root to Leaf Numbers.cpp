/**
 * Leetcode Problem- https://leetcode.com/problems/sum-root-to-leaf-numbers/
 * Author - Shubham Nagaria
 * Date - 3rd Nov 2021
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
    int res=0;
    void sumLoop(TreeNode* node, int s){
        if (!node)
            return; 
        s=(s*10)+node->val;
        if((node->left==nullptr) && (node->right==nullptr))
            res+=s;
         sumLoop(node->left,s);
         sumLoop(node->right,s);
    }
    int sumNumbers(TreeNode* root) {
        sumLoop(root,0);
        return res;
        
    }
};
