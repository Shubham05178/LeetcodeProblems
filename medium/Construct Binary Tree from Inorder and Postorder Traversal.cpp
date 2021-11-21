/**
* Leetcode Problem - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
        int postIndex;
    vector < int > postOrder;
    unordered_map<int, int> map;
    TreeNode * construct(int startIndex, int endIndex) {
        if (startIndex > endIndex) {
            return NULL;
        }
        TreeNode * node = new TreeNode(postOrder[postIndex]);
        --postIndex;
        if (startIndex == endIndex)
            return node;
        int index =map[node->val];
        node -> right = construct(index + 1, endIndex);
        node -> left = construct(startIndex, index - 1);

        return node;
    }

    TreeNode * buildTree(vector < int > & inorder, vector < int > & postorder) {
        postIndex = inorder.size() - 1;
        postOrder = postorder;
        for(int i =0 ; i <= postIndex; i++)
            map[inorder[i]]=i;
            return construct(0, postIndex);
    }
};
