// 🎯Problem Explaination:
// The "Smallest String Starting From Leaf" problem asks us to find the lexicographically smallest string that starts from a leaf and ends at the root in a given binary tree, where each node contains a lowercase letter.

// 🧠Thinking Behind the Solution:
// We will use a recursive DFS traversal where:

// At each node, we'll append the current node's character to a string.
// If it's a leaf node (both children are null), we'll reverse the string (since we're building from leaf to root) and compare it with the smallest string found so far.
// Recursively continue the traversal for left and right children.
// Here's why DFS is preferred for this task:

// Depth-First Search (DFS): DFS is suitable for problems where you need to explore as far as possible along each branch before backtracking which perfectly alings to our problem requirement.

// Breadth-First Search (BFS): BFS can also be used be solve this problem but with little more modifications to the traversal. Because BFS is ideal for finding the shortest path in an unweighted graph or tree. It explores all the neighboring nodes at the present depth before moving on to nodes at the next depth level.

// Approach✅:
// We are given a binary tree where each node contains a lowercase letter ('a' to 'z').
// Our goal is to find the lexicographically smallest string that starts from any leaf node and ends at the root.
// We'll use a recursive DFS traversal to explore the tree.
// Explanation of DFS Function (dfs()):
// This function performs the depth-first search traversal.
// node is the current node being processed.
// path is the list that stores the current path of characters (from root to current node).
// smallest is a list containing the smallest string found (using list to pass by reference).
// Processing Inside dfs():
// If node is None, we return immediately (base case for recursion).
// Append the current node's character (derived from node.val) to the path.
// If node is a leaf node (both node.left and node.right are None), construct the current string by reversing path and compare it with the smallest string found so far (smallest[0]).
// Recursively call dfs() for the left and right child nodes to continue the traversal.
// Backtrack by removing the last character (current node's character) from path after exploring a node.
// Initializing and Calling smallestFromLeaf():
// Initialize smallest with a large value ('z' + 1) to ensure it gets updated with the smallest string found during traversal.
// Call dfs() starting from the root of the binary tree with an empty path.
// Return the smallest string (smallest[0]) after traversal completes.
// Edge Cases:
// Handle cases where the tree is empty (root is None).
// Handle cases where the tree has a single node (the root is also a leaf).

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string smallest;
        dfs(root, "", smallest);
        return smallest;
    }
    
    void dfs(TreeNode* node, string path, string& smallest) {
        if (node == nullptr) return;
        
        // Append current node's character to the path
        path += char('a' + node->val);
        
        // If it's a leaf node, compare and update smallest
        if (node->left == nullptr && node->right == nullptr) {
            reverse(path.begin(), path.end());
            if (smallest.empty() || path < smallest) {
                smallest = path;
            }
            reverse(path.begin(), path.end()); // backtrack by reversing again
        }
        
        // Recursively traverse left and right subtrees
        dfs(node->left, path, smallest);
        dfs(node->right, path, smallest);
    }
};
