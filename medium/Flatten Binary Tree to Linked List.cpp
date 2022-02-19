/**
* Leetcode Problem - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
* Author - Shubham Nagaria
* Date - 20th Feb 2022
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
    void flatten(TreeNode* root) {
        TreeNode *curr =root, *temp;
        while(curr!= NULL){
            if(curr->left == NULL)
                curr= curr->right;
            else{
                temp = curr->left;
                while(temp->right!= NULL)
                    temp = temp->right;
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                curr = curr->right;
            }
        }
    }
};
