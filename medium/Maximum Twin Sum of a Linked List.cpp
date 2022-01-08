/**
* Leetcode Problem - https://leetcode.com/contest/biweekly-contest-69/problems/maximum-twin-sum-of-a-linked-list/
* Author - Shubham Nagaria
* Date - 9th Jan 2022
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
    int pairSum(ListNode* head) {
        ListNode* slow=head, *fast=head;
        while(fast ==NULL || fast->next->next!=NULL){
            slow=slow->next;
            fast = fast->next->next;
        }
       
        ListNode* head2 = slow->next;
        ListNode*curr= head2, *nex = curr, *prev = NULL;
        slow->next = NULL;
        while(nex!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev = curr;
            curr=nex;
        }        
        head2=prev;
        int ans=0;
        slow=head;
        fast=head2;
        while(slow!= NULL){
            ans = max( ans, slow->val+fast->val);
            fast = fast->next;
            slow=slow->next;
        }
        return ans;
    }
};
