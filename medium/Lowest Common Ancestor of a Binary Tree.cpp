/**
* Leetcode Problem - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
* Author - Shubham Nagaria
* Date - 19th Feb 2022
**/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root, TreeNode* s,vector<TreeNode*>& res){
        if(root== NULL) return false;
        if(root == s){
            res.push_back(root);
            return true;
        }
        if(path(root->left,s, res) || path(root->right,s,res)){
            res.push_back(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>pathpfromRoot, pathqfromRoot;  
        path(root, p, pathpfromRoot);
        path(root, q, pathqfromRoot);
        int i = pathpfromRoot.size()-1;
        int j = pathqfromRoot.size()-1;
        TreeNode * temp;
        while( i>=0 && j>=0 && pathpfromRoot[i]==pathqfromRoot[j]){
            temp = pathpfromRoot[i];
            i--;
            j--;
        }
        return temp;
    }
};
