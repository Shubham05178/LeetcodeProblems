/**
* Leetcode Problem - https://leetcode.com/problems/longest-univalue-path/
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
    pair<int,int>Traverse( TreeNode *node, int &lu){
        if(node == NULL) return {INT_MIN,0};
        auto l = Traverse(node->left,lu);
        auto r = Traverse(node->right,lu);
        if(l.first == r.first && l.first == node->val){
            lu = max(lu, l.second+r.second+2);
            return make_pair(node->val, max(l.second,r.second)+1);
        }
        else if(l.first == node->val){
            lu = max(lu , l.second+1);
            return make_pair(node->val,l.second+1);
        }
        else if(r.first == node->val){
            lu = max(lu, r.second+1);
            return make_pair(node->val, r.second+1);
        }
        return {node->val,0};
    }
    int longestUnivaluePath(TreeNode* root) {
        int l = 0;
        Traverse(root,l);
        return l;
    }
};
