# This Python snippet defines a class `Solution` with a method `hasCycle` that checks if a linked list has a cycle. 
# It uses the two-pointer technique with a slow pointer and a fast pointer to traverse the linked list. The `fast` pointer 
# moves two steps at a time while the `slow` pointer moves one step at a time. If there is a cycle in the linked list, the 
# fast pointer will eventually catch up with the slow pointer. If they meet at any point during traversal, it means there 
# is a cycle, and the method returns `True`. If the fast pointer reaches the end of the list (i.e., `None`), it means there 
# is no cycle, and the method returns `False`.

# Time complexity : O(N)
# Space complexity : O(1)

# The two-pointer technique for detecting cycles in a linked list offers several advantages:
# 1. **Efficiency**: It provides a more efficient way to detect cycles compared to using a hash table or other methods. 
# The two-pointer approach has a time complexity of O(n) and a space complexity of O(1), making it very efficient for cycle detection in linked lists.
# 2. **Constant Space**: The technique uses only two pointers, the slow and fast pointers, which means it requires constant 
# extra space regardless of the size of the linked list. This is beneficial for memory management.
# The speed of the fast pointer directly affects the efficiency of cycle detection. By moving two steps at a time, the fast pointer 
# covers more ground in each iteration compared to the slow pointer. This speed difference allows the fast pointer to catch up with 
# the slow pointer if there is a cycle in the linked list. If there is no cycle, the fast pointer will reach the end of the list (i.e., become `None`) before the slow pointer, indicating the absence of a cycle.
# The significance of the fast pointer reaching the end of the list lies in the fact that if there is no cycle, the fast pointer 
# will eventually reach the end of the list, which means it has traversed the entire linked list without encountering the slow pointer again. 
# This scenario confirms that there are no repeated nodes in the linked list, indicating the absence of a cycle.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = slow = head
        
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if fast == slow:
                return True
        
        return False
        
