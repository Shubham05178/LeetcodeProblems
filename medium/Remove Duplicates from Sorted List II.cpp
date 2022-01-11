/**
* Leetcode Problem - https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
* Author - Shubham Nagaria
* Date - 11th Jan 2022
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* frwd=head;
        ListNode* dummy = new ListNode(1);
        dummy->next = head;
        ListNode *h1= dummy;
        int cn;
        while(frwd!=nullptr){
            cn=1;
            while(frwd->next !=nullptr && frwd->val==frwd->next->val) cn++,frwd=frwd->next;      
            if(cn==1) dummy->next=frwd, dummy=dummy->next;
            frwd=frwd->next;
        }
        dummy->next=nullptr;
        return h1->next;
    }
};
