/**
* Leetcode Problem - https://leetcode.com/problems/univalued-binary-tree/
* Author - Shubham Nagaria
* Date - 1st March 2022
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
    bool isUnivalTree(TreeNode* root) {
        bool chck = false;
        int val = root->val;
        queue<TreeNode*>q;
        TreeNode* front;
        q.push(root);
        while(!q.empty()){
            front = q.front();
            q.pop();
            if(front->val != val) 
                return false;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        return true;
    }
};
