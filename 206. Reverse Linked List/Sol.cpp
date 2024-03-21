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
    ListNode* reverseList(ListNode* head) {
       ListNode* temp = head;  
   
   // Initialize pointer 'prev' to NULL,
   // representing the previous node
   ListNode* prev = NULL;  
   
   // Traverse the list, continue till
   // 'temp' reaches the end (NULL)
   while(temp != NULL){  
       // Store the next node in
       // 'front' to preserve the reference
       ListNode* front = temp->next;  
       
       // Reverse the direction of the
       // current node's 'next' pointer
       // to point to 'prev'
       temp->next = prev;  
       
        // Move 'prev' to the current
        // node for the next iteration
       prev = temp;  
       
        // Move 'temp' to the 'front' node
        // advancing the traversal
       temp = front;  
    }
   return prev;  
    }
};

// This code snippet is a C++ implementation of a function called `reverseList` that reverses a singly-linked list. 
// It defines a struct `ListNode` representing a node in the linked list with an integer value `val` and a pointer to the
//  next node `next`. The `reverseList` function takes the head of the linked list as input and iterates through the list, 
// reversing the direction of the `next` pointers to reverse the list. It uses three pointers: `temp` to traverse the list, 
// `prev` to keep track of the previous node, and `front` to store the next node temporarily. Finally, it returns the new 
// head of the reversed list.

// The reverseList function determines the new head of the reversed list by returning the pointer to the last node of the original list, 
// which becomes the first node in the reversed list after the reversal process. This is achieved by updating the prev pointer to point to 
// the current node during each iteration of the list traversal. Finally, when the traversal is complete, prev points to the last node 
// of the original list, which is now the first node of the reversed list, so it returns prev as the new head of the reversed list.
