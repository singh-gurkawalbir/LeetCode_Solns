# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        start = ListNode()
        start.next = head
        fast = start
        slow = start     

        for i in range(1, n+1):
            fast = fast.next
    
        while fast.next:
            fast = fast.next
            slow = slow.next
        
        slow.next = slow.next.next
        
        return start.next

# This Python snippet defines a class Solution with a method removeNthFromEnd that removes the nth node from 
# the end of a singly-linked list. It uses two pointers, fast and slow, to achieve this. The fast pointer moves 
# n steps ahead of the slow pointer. Then, both pointers move together until fast reaches the end of the list. 
# At this point, the slow pointer is at the node before the one to be removed, so it updates its next pointer 
# to skip the node to be removed. Finally, it returns the modified linked list starting from start.next.
# The purpose of using two pointers, fast and slow, in this method is to efficiently find the node that needs 
# to be removed from the singly-linked list. The fast pointer moves n steps ahead of the slow pointer, which 
# allows the slow pointer to be positioned at the node before the one to be removed when fast reaches the end 
# of the list. This approach optimizes the traversal of the linked list and enables the removal of the desired 
# node in a single pass without the need to traverse the list multiple times.
