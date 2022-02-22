/**
* Leetcode Problem - https://leetcode.com/problems/most-frequent-subtree-sum/
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
    int traverse(TreeNode* node,unordered_map<int,int>& mp,int& m){
        if(node == NULL) return 0;
        int sum = traverse(node->left, mp, m)+traverse(node->right,mp,m)+node->val;
        mp[sum]++;
        m = max(m, mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>mp;
        int m = 0;
        traverse(root, mp , m);
        vector<int>res;
        for(auto i : mp){
            if(m == i.second)
                res.push_back(i.first);
        }
        return res;
    }
};
