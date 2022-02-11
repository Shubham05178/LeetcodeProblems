/**
* Leetcode Problem - https://leetcode.com/problems/average-of-levels-in-binary-tree/
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
    vector<double> averageOfLevels(TreeNode* root) {
        double s = 0, i = 0;
        vector<double>res;
        TreeNode *prev = NULL ,*front;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(q.size() > 1 || prev != NULL){
            front = q.front();
            q.pop();
            if(front == NULL){
                res.push_back(s/i);
                i=0;
                s=0;
                q.push(NULL);
            }
            else{
                i++;
                s+=front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            prev = front;
        }
        return res;
    }
};
