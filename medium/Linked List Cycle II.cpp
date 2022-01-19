/**
* Leetcode Problem - https://leetcode.com/problems/linked-list-cycle-ii/
* Author - Shubham Nagaria
* Date - 19th Jan 2022

**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode * slow =head , *fast = head;
        do{
            slow = slow->next;
            if(fast->next!=NULL) fast = fast->next->next;
        }
        while(fast  != NULL && fast->next != NULL && slow!= fast);
        if (fast==NULL || fast->next==NULL) return NULL;
        fast = head;
        while(fast !=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};
