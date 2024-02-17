class Solution {
public:
     int maxDifference = 0;

    void findMaxAncestorDifference(TreeNode* currentNode, int minValue, int maxValue) {
        if (currentNode) {
            minValue = std::min(minValue, currentNode->val);
            maxValue = std::max(maxValue, currentNode->val);
            maxDifference = std::max(maxDifference, maxValue - minValue);

            findMaxAncestorDifference(currentNode->left, minValue, maxValue);
            findMaxAncestorDifference(currentNode->right, minValue, maxValue);
        }
    }

    int maxAncestorDiff(TreeNode* root) {
        findMaxAncestorDifference(root, root->val, root->val);
        return maxDifference;
    }
};

// Intuition:
// The goal is to find the largest absolute difference between a node and any of its ancestors in a binary tree.

// Approach :
// Initialize:
// Begin by initializing the minimum (minValue) and maximum (maxValue) values to the value of the root node. These values represent the range of values encountered during the traversal.

// Traverse Tree (Recursive):
// Use a recursive approach to traverse the binary tree. Start with the root node and explore its left and right subtrees.

// Update Min/Max:
// During the traversal, update the minimum and maximum values (minValue and maxValue) based on the values of nodes encountered. This ensures that they represent the range of values from the root to the current node.

// Calculate Node Difference:
// For each node visited, calculate the difference between the current node's value and the updated minimum and maximum values. This represents the difference between the node and its ancestors.

// Update Global Max Difference:
// Keep track of the global maximum difference (maxDifference). If the calculated difference at the current node is greater than the current maxDifference, update it.

// Recursive Exploration:
// Recursively explore the left and right subtrees of the current node, continuing the process of updating min/max values and checking for larger differences.

// Return Result:
// After the traversal is complete, return the calculated maxDifference. This value represents the maximum ancestor difference in the entire binary tree.

// Complexity:
// Time: O(N) (linear, N: nodes in the tree).
// Space: O(H) (height of the tree).

// Conclusion:
// Efficiently uses recursion to traverse the tree, updating min/max values and calculating the max ancestor difference. Suitable for large trees with a linear time complexity.
