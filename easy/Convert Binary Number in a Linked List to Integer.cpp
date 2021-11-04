/**
* Leetcode Problem - https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
* Author - Shubham Nagaria
* Date - 4th Nov 2021
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
    int getDecimalValue(ListNode* head) {
        int binary=0;
        while(head){
            binary= (binary+binary)+(head->val);
            head=head->next;
        }
        return binary;
        
    }
};


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res=0;
        while(head){
            res=(res<<1)+head->val;
            head=head->next;
        }
        return res;
    }
};
