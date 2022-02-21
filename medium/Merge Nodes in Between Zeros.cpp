/**
* Leetcode Problem - https://leetcode.com/problems/merge-nodes-in-between-zeros/
* Author - Shubham Nagaria
* Date - 21st Feb 2022
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *curr = head, *next;
        while(curr != NULL){
            if(curr->val==0){
                next = curr->next;
                curr->next = NULL;
                while(next != NULL && next->val != 0){
                    curr->val += next->val;
                    next = next->next;
                }
                if(next->next)
                    curr->next = next;
                curr = curr->next;
            }
        }
        return head;
    }
};


class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        int sum;
        while(fast!= NULL){
            sum = 0;
            while( fast != NULL && fast->val !=0 ){
                sum+=fast->val;
                fast= fast->next;
            }
            slow->val = sum;
            if(fast->next)
                slow = slow->next;
            fast =fast->next;
        }
        slow->next = NULL;
        return head;
    }
};
