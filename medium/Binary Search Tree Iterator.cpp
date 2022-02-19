/**
* Leetcode Problem - https://leetcode.com/problems/binary-search-tree-iterator/ 
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
class BSTIterator {
public:
    int i = 0;
    vector<int>res;
    BSTIterator(TreeNode* root) {
        TreeNode *curr;
        res.clear();
        i=0;
        curr = root;
        TreeNode *temp;
        while(curr!= NULL){
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr= curr->right;
            }
            else{
                temp = curr->left;
                while(temp->right != NULL && temp->right!= curr)
                    temp = temp->right;
                if(temp->right == NULL){
                    temp->right = curr;
                    curr = curr->left;
                }
                else{
                    temp->right = NULL;
                    res.push_back(curr->val);
                    curr= curr->right;
                }
            }
        }
    }
    
    int next() {
        return res[i++];
    }
    
    bool hasNext() {
        if(i<res.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
