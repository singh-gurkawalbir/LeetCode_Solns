Intuition:

We'll rearrange the linked list using three key steps: finding the middle node, reversing the second half, and merging the two halves in an alternating pattern.
Approach:

Find the Middle Node:

Initialize slow and fast pointers to head.
While fast and fast->next exist, move slow one step and fast two steps.
slow will now point to the middle node.
Reverse the Second Half:

Call reverse(slow) to reverse the list starting from slow.
This returns the new head of the reversed portion (list2).
Merge the Two Halves:

Keep a prev pointer to set prev->next to NULL later, marking the end of the first half.
Iterate through list1 and list2:
Store list1->next as nextNode.
Connect list1->next to list2.
Move list1 to nextNode.
Move list2 to list2->next.
Time Complexity:

Finding middle: O(n)
Reversing: O(n/2) ~ O(n)
Merging: O(n)
Total: O(3n) ~ O(n)
Space Complexity:

Extra pointers: O(1)
Recursive reverse call stack: O(n) in worst-case (extremely long lists), but practically considered O(1).
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
    ListNode* reverse(ListNode *head){
        if(!head) return NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextNode = NULL;
        while(curr){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    void merge(ListNode *list1, ListNode *list2){
        while(list2) {
            ListNode  *nextNode = list1->next;
            list1->next = list2;
            list1 = list2;
            list2 = nextNode;

        }

    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        while(fast && fast->next){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = NULL;
        ListNode *list1 = head;
        ListNode *list2 = reverse(slow);
        merge(list1,list2);
    }
}
Dry Run:

Example: head = [1, 2, 3, 4]

Find Middle:

slow = 1, fast = 4 (after loop)
Middle node: slow = 2
Reverse:

list2 = reverse(2) = 4 -> 3 -> 2
Merge:

list1 = 1 -> 2 -> 3 -> 4, list2 = 4 -> 3 -> 2
Iteration 1: list1 = 1 -> 4, list2 = 3 -> 2, prev->next = NULL
Iteration 2: list1 = 4 -> 3, list2 = 2
Final list: 1 -> 4 -> 2 -> 3
