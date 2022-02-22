/**
* Leetcode Problem - https://leetcode.com/problems/find-mode-in-binary-search-tree/
* Author - Shubham Nagaria
* Date - 22nd Feb 2022
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
    void traverse(TreeNode* node, unordered_map<int,int>& mp,int& m){
        if(node == NULL) return;
        mp[node->val]++;
        m = max(m, mp[node->val]);
        traverse(node->left,mp,m);
        traverse(node->right,mp,m);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        int m = 0;
        traverse(root,mp,m);
        vector<int>res;
        for(auto i : mp){
            if(i.second == m)
                res.push_back(i.first);
        }
        return res;
    }
};




class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int>res;
        if(root==NULL) return res;
        int count = 0;
        int maxcount =INT_MIN;
        TreeNode* curr = root,*temp;
        int p=INT_MIN,c=INT_MIN;
        while(curr!=NULL){
            if(curr->left== NULL){
                    p=c;
                    c=curr->val;
                    if(p!=c) count=1;
                    else count++;
                    if(count>maxcount){
                        res.clear();
                        res.push_back(c); 
                        maxcount=count;
                    }
                    else if(count==maxcount)
                        res.push_back(c);
                    curr=curr->right;
            }
            else{
                temp= curr->left;
                while(temp->right!=NULL && temp->right!=curr)
                    temp=temp->right;
                if(temp->right == NULL){
                    temp->right = curr;
                    curr=curr->left; 
                }
                else{
                    temp->right = NULL;
                    p=c;
                    c=curr->val;
                    if(p!=c) count=1;
                    else count++;
                    if(count>maxcount){
                        res.clear();
                        res.push_back(c);
                        maxcount=count;
                    }
                    else if(count==maxcount)
                        res.push_back(c);
                    curr=curr->right;
                }
            }
        }
        return res;
    }
};
