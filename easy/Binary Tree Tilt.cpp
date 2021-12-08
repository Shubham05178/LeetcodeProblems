/**
* Leetcode problem - https://leetcode.com/problems/binary-tree-tilt/
* Author - Shubham Nagaria
* Date - 8th Dec 2021
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
    int s = 0;
  int NodeSum(TreeNode * node) {
    if (node == NULL)
      return 0;
    int right = NodeSum(node -> right);
    int left = NodeSum(node -> left);
    s += abs(right - left);
    return node -> val + left + right;
  }
  int findTilt(TreeNode * node) {
    NodeSum(node);
    return s;
  }
};
