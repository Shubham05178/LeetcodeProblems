/**
* Leetcode Problem - https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
* Author - Shubham Nagaria
* Date - 22nd Feb 2022
Note - Today Date is Pallindrome - 22022022
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
    int mod =1e9+7;
    long long int sumProductMax(TreeNode* node,const long long int &sum,long long int& mul){
        if(node == NULL) return 0;
        long long int l= sumProductMax(node->left,sum,mul);
        long long int r=sumProductMax(node->right,sum,mul);
        long long sum_ = l+r+node->val;
        mul= max(mul, (sum - sum_ ) * sum_ );
        return  sum_;
    }
     void sumTraverse(TreeNode * node,long long int &sum){
       if(node == NULL) return;
        sumTraverse(node->left,sum);
        sumTraverse(node->right,sum);
        sum+= node->val;
     }
    int maxProduct(TreeNode* root) {
        long long int sum=0;
        sumTraverse(root,sum);
        long long int mul =INT_MIN;
        sumProductMax(root,sum,mul);
        return mul%mod;
    }
};
