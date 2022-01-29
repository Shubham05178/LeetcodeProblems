/**
* Leetcode Problem - https://leetcode.com/problems/sort-list/
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
    ListNode* mergeSort(ListNode *A, ListNode *B){
        ListNode *h = new ListNode(-1);
        ListNode *curr = h;
        while(A != NULL && B != NULL){
            if(A->val < B->val){
                curr->next = A;
                A = A->next;
                curr = curr->next;
                curr->next = NULL;
            }
            else{
                curr->next = B;
                B = B->next;
                curr = curr->next;
                curr->next = NULL;
            }
        }
        if(A != NULL) curr->next = A;
        if(B != NULL) curr->next = B;
        return h->next;
    }
    ListNode* middlelist(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow= head, *fast=head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow= slow->next;
        }
        return slow;
    }
    ListNode* divideandmerge(ListNode* head){
        if(head->next == NULL) return head;
        ListNode *mid = middlelist(head);
        ListNode *midnext = mid->next;
        mid->next = NULL;
        ListNode *head1 = divideandmerge(head);
        ListNode *head2 = divideandmerge(midnext);
        return mergeSort(head1,head2);
    }
    ListNode* sortList(ListNode* head) {
        if(head== NULL || head->next == NULL) return head;
        return divideandmerge(head);
    }
};
