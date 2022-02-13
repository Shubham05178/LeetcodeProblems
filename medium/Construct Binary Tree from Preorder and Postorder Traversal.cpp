/**
* Leetcode Problem - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
* Author - Shubham Nagaria
* Date - 13th Feb 2022
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
    TreeNode* construct(vector<int>& preorder,int prs, int pre,vector<int>& postorder, int pos, int poe, unordered_map<int,int>& mp){
        if(prs > pre) return NULL;
        TreeNode* node = new TreeNode( preorder[prs]);
        if(prs == pre) return node;
        int x = mp[preorder[prs+1]];
        int l = x - pos;
        node->left = construct(preorder,prs + 1,prs + l+1, postorder, pos , pos + l, mp);
        node->right = construct(preorder,prs + l + 2, pre, postorder, pos + l + 1 ,poe - 1, mp);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n = postorder.size()-1;
        for(int i = 0; i <= n ; i++)
            mp[postorder[i]] = i;
        return construct(preorder, 0, n , postorder , 0 , n, mp);
    }
};
