/**
* Leetcode Problem - https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
* Author - Shubham Nagaria
* Date - 28th Jan 2022
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curr = head, *slow = head,*fast = NULL;
        while(--k && curr != NULL)
            curr = curr->next;
        fast = curr;
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        int temp= slow->val;
        slow->val= curr->val ;
        curr->val = temp;
        return head;
    }   
};
