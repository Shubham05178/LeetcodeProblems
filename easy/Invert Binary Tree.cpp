/**
 * Leetcode Problem - https://leetcode.com/problems/invert-binary-tree/
 * Author - Shubham Nagaria
 * Date - 25th Oct 2021
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
void solve(TreeNode* root){
if(!root) return;

    solve(root->left);
    solve(root->right);
	/*first go to the bottom of tree, start with swaping the subtree accociated with the particular node
	if any of its two child is not NULL*/
    if(root->left || root->right)
    swap(root->left,root->right);

}
TreeNode* invertTree(TreeNode* root) {
    if(root==NULL) return NULL;
    solve(root);
    return root;
}
};
