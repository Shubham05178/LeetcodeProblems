/**
 * Leetcode Problem - https://leetcode.com/problems/reverse-linked-list/
 * Author - Shubham Nagaria
 * Date - 25th Oct 2021
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev =NULL;
        ListNode* current =head;
        if (head ==NULL || head-> next==NULL)
            return head;
        ListNode* next1=head->next;
        while(current!=NULL){
            current->next=prev;
            prev=current;
            current=next1;
            if (next1!=NULL)
            next1=next1->next;

        }
        return prev;
    }
};
