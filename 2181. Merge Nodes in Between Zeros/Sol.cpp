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



Example
Let's consider an example:

Input List: 0 -> 1 -> 3 -> 0 -> 2 -> 2 -> 0

Initial List:

0 -> 1 -> 3 -> 0 -> 2 -> 2 -> 0
Skip Initial Zero:

head points to: 1 -> 3 -> 0 -> 2 -> 2 -> 0
First Iteration:

start points to 1.
end points to 1.
Sum values until 0:
sum = 1 + 3 = 4
Update start->val to 4.
Update start->next to skip zero:

4 -> 2 -> 2 -> 0
Second Iteration:

start points to 2.
end points to 2.
Sum values until 0:
sum = 2 + 2 = 4
Update start->val to 4.
Update start->next to skip zero:

4 -> 4
Final List:

4 -> 4
So, the mergeNodes method merges nodes between zeros and returns a list of summed values.







