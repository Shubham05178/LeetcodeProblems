/**
* Leetcode Problem - https://leetcode.com/problems/find-largest-value-in-each-tree-row/
* Author - Shubham Nagaria
* Date - 23rd Feb 2022
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
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        if(root == NULL) return res;
        queue<TreeNode*>q;
        q.push(root);
        int m,l;
        TreeNode * front;
        while(!q.empty()){
            l = q.size();
            m = q.front()->val;
            while(l--){
                front = q.front();
                q.pop();
                m = max(m, front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            res.push_back(m);
        }
    return res;
    }
};
