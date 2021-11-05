/**
* Leetcode Problem -https://leetcode.com/problems/intersection-of-two-linked-lists/
* Author - Shubham Nagaria
* Date - 5th Nov 2021
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL  || headB ==NULL)
            return nullptr;
        ListNode* a_pointer = headA;
        ListNode* b_pointer = headB;
        while(a_pointer!=b_pointer){
           a_pointer=a_pointer==NULL?headB:a_pointer->next;
           b_pointer=b_pointer==NULL?headA:b_pointer->next;
        }
        return a_pointer;
    }
};
