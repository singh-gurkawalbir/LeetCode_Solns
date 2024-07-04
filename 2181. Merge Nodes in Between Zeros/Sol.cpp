class Solution {
public:
   ListNode* mergeNodes(ListNode* head) {
     head=head->next;
     ListNode* start=head;
     while(start){
	    ListNode* end= start;   
        int sum=0;
        while(end->val!=0) sum+= end->val , end=end->next;
        start->val=sum;   
        start->next=end->next;  
        start=start->next;   
	 }
     return head;
}
};

// Explanation
// Initialization:
// The head of the list is updated to skip the initial zero.
// A start pointer is used to iterate through the list.
// Merging Nodes:
// For each segment between zero nodes, a nested loop calculates the sum of node values.
// The end pointer helps in traversing these segments.
// The calculated sum is assigned to the node at the start pointer.
// The next pointer of the start node is updated to bypass the segment and point to the next zero node.
// Iteration:
// The start pointer moves to the next segment and repeats the process.
// Example
// Consider the linked list:

// 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0
// The steps would be:

// Skip the initial 0.
// Sum nodes 3 + 1 = 4, and update the list to 4 -> 0 -> 4 -> 5 -> 2 -> 0.
// Sum nodes 4 + 5 + 2 = 11, and update the list to 4 -> 11 -> 0.
// The final merged list is:
// 4 -> 11
