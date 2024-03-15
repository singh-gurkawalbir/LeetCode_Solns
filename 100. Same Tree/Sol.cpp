// Explanation
// Objective: Determine if two binary trees are identical.
// Base Case: Return true if both trees are null.
// Null Comparison: If only one tree is null while the other isn't, return false.
// Value Comparison: If values of the current nodes are not equal, return false.
// Recursive Call: Recur for left and right subtrees of both trees.
// Result: Return true if all comparisons are equal, else false.
// Time Complexity-O(n)
// Space Complexity-O(h) height of the tree
//Demo commit
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
