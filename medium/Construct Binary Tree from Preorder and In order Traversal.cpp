/**
* Leetcode Problem - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* construct(vector<int>& preorder, int ps, int pe,vector<int>& inorder, int ins, int ine, unordered_map<int,int>& mp){
        if(ps>pe) return NULL;
        TreeNode* Node = new TreeNode(preorder[ps]);
        int x= mp[preorder[ps]]-ins;
        Node->left=construct(preorder,ps+1,ps+x,inorder,ins,mp[preorder[ps]]-1,mp);
        Node->right=construct(preorder, ps+x+1,pe,inorder,mp[preorder[ps]]+1,ine,mp);
        return Node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int len = inorder.size()-1;
        for(int i = 0; i <= len; i++)
            mp[inorder[i]]=i;
        return construct(preorder,0,len,inorder,0,len ,mp);
    }
};
