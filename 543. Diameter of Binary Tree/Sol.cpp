class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode* node, int& diameter) {

        if (!node) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};

// Time Complexity (TC): O(N)
// Space Complexity (SC): O(H), where H is the height of the binary tree

// Dry Run:

// Consider the binary tree:

// markdown
// Copy code
//     1
//    / \
//   2   3
//  / \
// 4   5
// Initial Call:

// The diameterOfBinaryTree function is called with the root of the tree (1).
// It initializes the diameter variable to 0 and then calls the height function.
// Height Function:

// The height function is a recursive function that calculates the height of each node in the tree.
// For the root (1), it calculates the left subtree's height (lh) by calling height on node 2 and the right subtree's height (rh) by calling height on node 3.
// It then calculates the diameter at the current node using diameter = max(diameter, lh + rh).
// Recursion:

// The recursion continues for nodes 2, 4, 5, and 3, calculating the height and updating the diameter.
// The height for the leaf nodes (4 and 5) is 0, and for nodes 2 and 3, it is 1.
// The diameter is updated at each step based on the formula diameter = max(diameter, lh + rh).
// Final Result:

// After the recursion completes, the diameterOfBinaryTree function returns the final diameter.
// Detailed Steps:

// Diameter at node 4: diameter = max(0, 0) = 0
// Diameter at node 5: diameter = max(0, 0) = 0
// Diameter at node 2: diameter = max(1, 1 + 0) = 1
// Diameter at node 3: diameter = max(1, 0 + 0) = 1
// Diameter at node 1: diameter = max(1, 1 + 1) = 2
// So, the diameter of the given binary tree is 2.
