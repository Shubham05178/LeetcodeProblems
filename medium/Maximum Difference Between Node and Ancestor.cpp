/**
* Leetcode Problem - https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
* Author - Shubham Nagaria
* Date - 31st Dec 2021
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
// O(N) Time complexity and O(N) space in worst case O(Log N) in best case space complexity 
class Solution {
public:
    int traverse(TreeNode* node, int curmax, int curmin){
        if(node == nullptr) return curmax-curmin;
        curmax=max(curmax,node->val);
        curmin=min(curmin,node->val);
        int left= traverse(node->left,curmax,curmin);
        int right= traverse(node->right,curmax,curmin);
        
        return max(left,right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root ==nullptr) return 0;
        return traverse(root,root->val,root->val);
    }
};
