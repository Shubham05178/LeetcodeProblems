/**
* Leetcode Problem- https://leetcode.com/problems/sum-of-left-leaves/
* Author- Shubham Nagaria  
* Date- 4th Nov 2021
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
    void checkandsum(TreeNode* root,int flag){
        if(root==nullptr)
            return;
        if(root->left==nullptr && root->right==nullptr && flag==0)
            res+=root->val;
        checkandsum(root->left,0);
        checkandsum(root->right,1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        checkandsum(root,-1);
        return res;
    }
};
