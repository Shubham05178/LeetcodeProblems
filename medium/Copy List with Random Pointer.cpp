/**
* Leetcode Problem - https://leetcode.com/problems/copy-list-with-random-pointer/
* Author - Shubham Nagaria
* Date - 24th Feb 2022
**/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* curr= head;
        while(curr){
            Node* node = new Node(curr->val);
            node->next = curr->next;
            curr->next=node;
            curr= node->next;
        }
        curr = head;
        while(curr){
            if(curr->random) curr->next->random = curr->random->next;
            curr= curr->next->next;
        }
        curr = head;
        Node* head2 = curr->next, * curr1 = curr->next;
        while(curr){
            curr->next= curr->next->next;
            curr=curr->next;
            if(curr)
            curr1->next = curr1->next->next;
            curr1=curr1->next;
        }
        return head2;
    }
};
