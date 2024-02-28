// Intuition
// First thought that comes in mind is using dfs and traverse to left most node but it will end up in giving wrong answer as the height is the main factor so to came up with a better solution bfs would be a good approach to traverse level wise

// Approach
// To understand the approach for the provided code snippet, let's break it down step by step:

// Objective: The goal of this code is to find the value of the leftmost node in the bottom level of a binary tree.
// Algorithm:

// The code uses a breadth-first search (BFS) approach to traverse the binary tree level by level.

// It starts by initializing a queue q with the root node.
// Then, it enters a loop where it dequeues a node, checks if it has a right child, and if so, adds it to the queue. Next, it checks for a left child and adds it to the queue.

// By doing this level-order traversal, the last node visited will be the leftmost node at the bottom level of the tree.
// Key Points:
// The code prioritizes visiting right child nodes before left child nodes in each level.

// The final value returned is from the last node visited, which will be the leftmost node at the deepest level of the tree.

// This approach ensures that by traversing the tree level by level from left to right, we can find and return the value of the leftmost node at the deepest level of the binary tree.

// Complexity
// Time complexity:0(n) each node is traversed once
// Space complexity:0(n) because of queue
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;

        q.push(root);
        TreeNode *a=NULL;
        while(!q.empty()){
            a = q.front();
            q.pop();

            if(a->right){
                q.push(a->right);
            }
            if(a->left){
                q.push(a->left);
            }
        }
        return a->val;
    }
};
