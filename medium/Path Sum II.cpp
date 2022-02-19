/**
* Leetcode Problem - https://leetcode.com/problems/path-sum-ii/
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
    void PathSum(TreeNode* node, vector<int>& r,vector<vector<int>>& res, int targetSum){
        if(node == NULL) return;
        if(node->left == NULL && node->right == NULL){
            if(targetSum == node->val){
                r.push_back(node->val);
                res.push_back(r);
                r.pop_back();
            }
            return;
        }
        r.push_back(node->val);
        if(node->left != NULL)
            PathSum(node->left,r, res , targetSum - node->val);
        if(node->right != NULL)
            PathSum(node->right,r,res, targetSum - node->val);
        r.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>r;
        PathSum(root, r ,res,targetSum);
        return res;
    }
};
