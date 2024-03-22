// Intuition
// To determine if a linked list is a palindrome, we can reverse the second half of the linked list and then compare it with the first half. If they match, the linked list is a palindrome.

// Approach
// We'll use a slow and fast pointer technique to find the middle of the linked list.
// Reverse the second half of the linked list starting from the middle node.
// Compare each node of the first half with the corresponding node of the reversed second half. If all nodes match, return true; otherwise, return false.
// Complexity
// Time complexity: O(n), where ( n ) is the number of nodes in the linked list. We traverse the list twice, once to find the middle and once to compare nodes.
// Space complexity: O(1) since we only use a constant amount of extra space.
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
    ListNode *reverse(ListNode * head){
        if(!head) return head;
        ListNode * prev = NULL;
        ListNode *curr = head;
        ListNode *nextnode = NULL;
        while(curr!=NULL){
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast !=NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
            }
        ListNode *ReverseHead = reverse(slow);
        ListNode *temp1 = head;
        ListNode *temp2 = ReverseHead;
        while(temp2!=NULL){
            if(temp1->val != temp2->val)
            return false;
            else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return true;
    }
// };
// Dry Run
// Let's dry run the code with an example:

// Input: head = [1,2,2,1]

// 1 -> 2 -> 2 -> 1 -> NULL
// Initialize slow and fast pointers at the head: slow = 1, fast = 1.
// Move fast two steps ahead and slow one step ahead in each iteration until fast reaches the end.
// Iteration 1: slow = 1, fast = 2
// Iteration 2: slow = 2, fast = 1 (reached end)
// Reverse the second half starting from the slow pointer:
// After reversal: 1 -> 2 <- 2 <- 1 (ReverseHead points to the new head)
// Compare each node of the first half with the corresponding node of the reversed second half:
// Node 1 (from the first half) matches with Node 2 (from the reversed second half)
// Node 2 (from the first half) matches with Node 2 (from the reversed second half)
// All nodes match, so return true.
// Therefore, the output is true.
