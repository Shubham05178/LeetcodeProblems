/**
* Leetcode Problem - https://leetcode.com/problems/merge-k-sorted-lists/
* Author - Shubham Nagaria
* Date - 29th Jan 2022
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
//Time Complexity - O(N log k) Space Complexity - O(1)
class Solution {
public:
    ListNode* mergeTwoList(ListNode* A, ListNode *B){
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
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
        if(B != NULL) curr->next = B;
        if(A != NULL) curr->next = A;
        return head->next;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
            return NULL;
        int interval = 1;
        while(interval < n){
            for( int i =0; i < n - interval;  i += interval*2 )
                lists[i] = mergeTwoList(lists[i],lists[i+interval]); 
            interval *= 2;
        }
        return lists[0]; 
    }
};
