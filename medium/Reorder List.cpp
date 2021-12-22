/**
* Leetcode Problem - https://leetcode.com/problems/reorder-list/
* Author - Shubham Nagaria
* Date - 22nd Dec 2021
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
//Uses O(1) space
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow =head,* fast =head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* head2=slow->next,*next=NULL,*curr=slow->next,*prev=NULL;
        slow->next=NULL;
        
        while(curr!= NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head2=prev;
        curr=head;
        while(head2!=NULL){
            next=curr->next;
            curr->next=head2;
            head2=head2->next;
            curr->next->next=next;
            curr=next;
        }
    }
};

//Another using stack uses O(N) Space

class Solution {
public:
    void reorderList(ListNode* head) {
    int l=0;
    stack<ListNode*> my;
    ListNode* ptr=head, *element ;
    while(ptr){
        my.push(ptr);
        l++;
        ptr=ptr->next;
    }
        ptr=head;
        for(int i =0; i< l/2;i++){
            element=my.top();
            element->next=ptr->next;
            ptr->next=element;
            my.pop();
            ptr=ptr->next->next;
        }
        ptr->next=NULL;
    }
};
