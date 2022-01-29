/**
* Leetcode Problem - https://leetcode.com/problems/reverse-linked-list-ii/
* Author - Shubham Nagaria
* Date - 30th Jan 2022
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *curr = dummyHead;
        while(--left > 0 && --right && curr != NULL){
            curr= curr->next;
        }
        ListNode *prev = NULL, *next = NULL , *tail = curr->next, *c = curr;
        curr=curr->next;
        while(right-- && curr!= NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail->next = curr;
        c->next = prev;
        return dummyHead->next;
        
    }
};
