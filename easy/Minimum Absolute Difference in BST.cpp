/**
* Leetcode Problems - https://leetcode.com/problems/minimum-absolute-difference-in-bst/
* Author - Shubham Nagaria
* Date - 23rd Feb 2022
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
    int getMinimumDifference(TreeNode* root) {
       int mindiff = INT_MAX, prev = INT_MAX;
        TreeNode* curr = root,* temp;
        while(curr){
            if(!curr->left){
                mindiff = min(mindiff,abs(prev - curr->val));
                prev = curr->val;
                curr=curr->right;
            }
            else{
                temp = curr->left;
                while(temp->right && temp->right != curr)
                    temp = temp->right;
                if(!temp->right){
                    temp->right = curr;
                    curr = curr->left;
                }
                else{
                    temp->right = NULL;
                    mindiff = min( mindiff, abs(prev - curr->val));
                    prev = curr->val;
                    curr = curr->right;
                }
            }
        }
        return mindiff;
    }
};
