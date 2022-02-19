/**
 * Leetcode Problem - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * Author - Shubham Nagaria
 * Date - 20th Feb 2022
*/
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
   pair<pair< ListNode*,ListNode*> int> midoflist (ListNode * head) {
       ListNode *slow = head,fast = head,*prev;
       prev =slow;
       while(fast && fast->next && fast->next->next){
           prev=slow;
           slow = slow->next;
           fast = fast->next->next;
       }
       fast =slow->next->next;
       int x = prev->val;
       slow->next = NULL;
      return make_pair(make_pair(head,fast),x);
   }
    TreeNode* sortedListToBST(ListNode* head) {
        auto 
    }
};
