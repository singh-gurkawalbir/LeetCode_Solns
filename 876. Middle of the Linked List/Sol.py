# Initialization: Start with two pointers, fast and slow, both pointing to the head of the list.

# Traversal: Move the fast pointer two steps at a time and the slow pointer one step at a time. This ensures that when the fast pointer reaches the end of the list, the slow pointer will be at the middle node.

# Find the Middle Node: After traversal, the slow pointer will be at the middle node of the list.

# Edge Case Handling: Check if the list is empty or contains only one node. In such cases, the middle node is the head itself.

# Return: Return the node pointed to by the slow pointer as the middle node.

# Complexity
# Time complexity:O(n)
# Space complexity:O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow = head
        fast = head

        while fast:
            fast = fast.next
            if fast:
                fast = fast.next
                slow = slow.next

        return slow
