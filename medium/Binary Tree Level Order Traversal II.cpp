/**
* Leetcode Problem - https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
* Author - Shubham Nagaria
* Date - 12th Feb 2022
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>a;
        if(root == NULL ) return res;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        TreeNode *prev=NULL,*front;
        while(q.size()>1 || prev!= NULL){
            front = q.front();
            q.pop();
            if(front == NULL){
                res.push_back(a);
                a.clear();
                q.push(NULL);
            }
            else{
                a.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            prev = front;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
