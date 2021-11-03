/**
 * Leetcode Problem- https://leetcode.com/problems/rotate-list/
 * Author - Shubham Nagaria
 * Date - 3rd Nov 2021
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        
        ListNode* curr=head;
        ListNode* prev=nullptr;
        int count = 0;
        while(curr!=nullptr)
        {
            count++;
            prev=curr;
            curr=curr->next;
        }
        k=k%count;
        if(k==0)
            return head;
        
        count-=k;
        curr=head;
        while(count>1){
            curr=curr->next;
            count--;   
        }
        prev->next=head;
        head=curr->next;
        curr->next=nullptr;
        return head;
    }
};
