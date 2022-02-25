/**
* Leetcode Problem - https://leetcode.com/problems/convert-bst-to-greater-tree/
* Author - Shubham Nagaria
* Date - 26th Feb 2022
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
     void traverse(TreeNode* root,long int& x){
       if (root == NULL) return;
        traverse(root->left,x);
        int c= root->val;
        root->val = x;
        x-= c;
        traverse(root->right,x);
    }
  long int sumTree(TreeNode* root){
        if(root == NULL) return 0;
        return 1LL* root->val +sumTree(root->left)+sumTree(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return root;
        long int x= sumTree(root);
        traverse(root,x);
        return root;
    }
};




class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode *curr = root ,*temp;
        long int x = 0;
        while(curr){
            if(!curr->right){
                curr->val += x;
                x = curr->val;
                curr = curr->left;
            }
            else{
                temp = curr->right;
                while(temp->left!= NULL && temp->left!=curr)
                    temp = temp->left;
                if(!temp->left){
                    temp->left = curr;
                    curr = curr->right;
                }
                else{
                    temp->left = NULL;
                    curr->val +=x;
                    x = curr->val;
                    curr= curr->left;
                }
            }
        }
        return root;
    }
};
