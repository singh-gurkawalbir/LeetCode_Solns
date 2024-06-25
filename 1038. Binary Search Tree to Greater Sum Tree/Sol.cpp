class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* node = root;
        stack<TreeNode*> s;
        int total = 0;
        while (node || !s.empty()) {
            while (node) {
                s.push(node);
                node = node->right;
            }
            node = s.top(); s.pop();
            total += node->val;
            node->val = total;
            node = node->left;
        }
        return root;
    }
};

// Complexity
// Time complexity: O(n)
// Space complexity: O(n)
// We should first visit the nodes with the largest value in a DFS while using a global variable to keep track of the current total. 
// If we visit the right nodes first then the left nodes, this ensures that for any given node, the total will be equal to the sum of all the 
// nodes greater than the current one since we visited the right subtree first.

// We can use a stack to do this iteratively. The process is more so the same. 
// We first push all current subtree's right nodes onto the stack and keep track of the total. 
// We pop from the top then switch to the left subtree and repeat.
