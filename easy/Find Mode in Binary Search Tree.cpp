/**
* Leetcode Problem - https://leetcode.com/problems/find-mode-in-binary-search-tree/
* Author - Shubham Nagaria
* Date - 22nd Feb 2022
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
    void traverse(TreeNode* node, unordered_map<int,int>& mp,int& m){
        if(node == NULL) return;
        mp[node->val]++;
        m = max(m, mp[node->val]);
        traverse(node->left,mp,m);
        traverse(node->right,mp,m);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        int m = 0;
        traverse(root,mp,m);
        vector<int>res;
        for(auto i : mp){
            if(i.second == m)
                res.push_back(i.first);
        }
        return res;
    }
};
