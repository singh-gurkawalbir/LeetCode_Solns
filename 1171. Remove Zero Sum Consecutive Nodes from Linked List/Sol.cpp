// Intuition
// To approach this problem, we can utilize a hashmap to keep track of the cumulative sum encountered while traversing the linked list. If we encounter 
// the same cumulative sum again, it means the subsequence between the current node and the node with the same cumulative sum sums to zero, so we can 
// remove that subsequence. To facilitate this removal, we maintain a dummy node to handle cases where the entire linked list needs to be modified.

// Approach
// Initialize a dummy node to handle cases where the entire linked list needs to be modified.
// Traverse the linked list, maintaining a cumulative sum and storing the sum along with the corresponding node in a hashmap.
// If we encounter a cumulative sum that already exists in the hashmap, it indicates a subsequence sums to zero. In this case, we remove the nodes between 
// the current node and the node corresponding to the encountered cumulative sum.
// Continue traversing until the end of the linked list.
// Return the modified linked list.
// Complexity
// - Time complexity: The algorithm has a time complexity of O(n), where n is the number of nodes in the linked list. This is because we traverse the linked list only once.
// - Space complexity: The space complexity is also O(n) because, in the worst case, we might need to store all nodes in the hashmap.

// Explanation of Dummy Node and Entry in Map
// Dummy Node (dummy): The dummy node is a placeholder at the beginning of the linked list. It helps handle cases where the first node needs to be removed. 
// By having a dummy node, we can easily modify the next pointers of nodes without worrying about special cases for the head of the linked list.
// Entry in Map (mp[0] = dummy): We initialize the hashmap with an entry mp[0] = dummy. This entry serves as a starting point for cumulative sums. When we 
// encounter a cumulative sum of zero, it means the sum from the beginning of the list to the current node is zero, and thus, we need to remove the nodes b
// etween the dummy node and the current node. This entry helps in handling such scenarios efficiently.

// /**
 // * Definition for singly-linked list.
 // * struct ListNode {
 // *     int val;
 // *     ListNode *next;
 // *     ListNode() : val(0), next(nullptr) {}
 // *     ListNode(int x) : val(x), next(nullptr) {}
 // *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 // * };
 // */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        unordered_map<int,ListNode*>mp;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;
        while(head != NULL){
            prefixSum += head->val;
            if(mp.find(prefixSum) != mp.end()){
                //delete the node
                ListNode *start = mp[prefixSum];
                ListNode *temp = start;
                int pSum = prefixSum;
                while(temp != head){
                    temp = temp->next;
                    pSum += temp->val;
                    if(temp != head)
                        mp.erase(pSum);
                }
                start->next = head->next;
            }
            else{
                mp[prefixSum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};
