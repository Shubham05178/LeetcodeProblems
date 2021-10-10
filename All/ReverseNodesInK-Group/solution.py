# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        reversedLinkedList = None
        tempLinkedList = None
        linkedList = head
        i = 0
        n = 0
        while linkedList:
            n += 1
            linkedList = linkedList.next
        n //= k

        linkedList = head
        while True:
            if i == k:
                if reversedLinkedList:
                    tempReversedLinkedList = reversedLinkedList
                    while tempReversedLinkedList.next:
                        tempReversedLinkedList = tempReversedLinkedList.next
                    tempReversedLinkedList.next = tempLinkedList
                else:
                    reversedLinkedList = tempLinkedList
                tempLinkedList = None
                i = 0
                n -= 1
            if n > 0:
                if tempLinkedList:
                    listNode = ListNode(linkedList.val)
                    listNode.next = tempLinkedList
                    tempLinkedList = listNode
                else:
                    tempLinkedList = ListNode(linkedList.val)
            else:
                if reversedLinkedList:
                    tempReversedLinkedList = reversedLinkedList
                    while tempReversedLinkedList.next:
                        tempReversedLinkedList = tempReversedLinkedList.next
                    tempReversedLinkedList.next = linkedList
                else:
                    reversedLinkedList = linkedList
                break
            i += 1
            linkedList = linkedList.next
        return reversedLinkedList
