/**
 * Leetcode Problem - https://leetcode.com/problems/linked-list-cycle/
 * Author - Shubham Nagaria
 * Date - 25th Oct 2021
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /** Solution - 1 **/


class Solution {
public:
    bool hasCycle(ListNode *head) {
    
        if(head==NULL)
            return false;
        ListNode* node=head;
        ListNode* p=NULL;
        ListNode *dummy=new ListNode;
        while(node!=NULL)
        {         
            
            if(node->next==dummy)
                return true;
            p=node->next;
            node->next=dummy;
            node=p;
            

        }
        return false;
    }
};


/** Solution - 2 **/


class Solution {
public:
    bool hasCycle(ListNode *head) {
    
        if(head==NULL)
            return false;
        ListNode * slow, *fast;
        slow=head;
        fast=head->next;

        while(slow!=NULL and fast!=NULL and fast->next!=NULL)
        {         
            
            if(slow==fast)
                return true;
            slow=slow->next;
            fast=fast->next->next;         
            

        }
        return false;
    }
};
