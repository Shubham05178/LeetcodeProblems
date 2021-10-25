/**
 * Leetcode Problem - https://leetcode.com/problems/merge-two-sorted-lists/
 * Author - Shubham Nagaria
 * Date - 25th Oct 2021
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        for(auto cur = &dummy; l1 || l2; cur = cur->next) {
            auto& l = l1 && (!l2 || l1->val < l2->val) ? l1 : l2;
            cur->next = l;
            l = l->next;
        }
        return dummy.next;
    }
};
