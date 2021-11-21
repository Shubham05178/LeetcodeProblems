/**
* Leetcode Problem - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
* Author - Shubham Nagaria
* Date - 21st Nov 2021

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
    int preIndex=0;
    vector<int> preorder;
    unordered_map<int,int> map;
    TreeNode* construct(int startIndex,int endIndex){
        if (startIndex>endIndex)
            return NULL;
        TreeNode* node=new TreeNode(preorder[preIndex]);
        int index=map[preorder[preIndex]];
        preIndex++;
        if(startIndex==endIndex)
            return node;
        node->left=construct(startIndex,index-1);
        node->right=construct(index+1,endIndex);
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inorder) {
        preorder=preOrder;
        for( int i =0 ; i < inorder.size();i++)
            map[inorder[i]]=i;
        return construct(0,inorder.size()-1);
    }
};
