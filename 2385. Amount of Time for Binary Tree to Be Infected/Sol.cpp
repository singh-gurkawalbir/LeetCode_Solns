// Intuition
// Use dfs and find a node with maximum distance from infected node.

// Approach
// Visit all the nodes from root node using dfs and check whether left subtree is infected or right subtree is infected or nothing infected yet.

// If current node is infected node

// Find the max_depth = max(left_subtree, right_subtree)
// Set it as a answer. Beacause infection starts from the infected node, and will end the infection in a node with maximum distance.
// Always consider three cases.

// Already infected Left subtree
// count total_node = all_node_from_infected_to_current_ancestor_node + all_right_node_from_current_ancestor+current_ancestor_node
// compare it with existing answer.
// Already infected Right subtree
// count total_node = all_node_from_infected_to_current_ancestor_node + all_left_node_from_current_ancestor+current_ancestor_node
// No subtree is infected yet.
// take the current maximum from left and right subtree.
// see the code for better understand. sorry for my poor english🙏🙏.

// Complexity
// Time complexity: $$O(n)$$
// Space complexity: $$O(n)$$

#define pii pair<int,int>
class Solution {
public:
    bool flag=false;
    // return number of node and direction
    // pair(n,dir)
    // dir = 0 means no infected
    // dir = 1 infected
    int ans = 0;
    pii dfs(TreeNode* root, int start) {
        if(root==nullptr) return make_pair(0,0);

        auto [left,dir1] = dfs(root->left, start);
        auto [right,dir2] = dfs(root->right, start);

        if(root->val==start) {
            ans = max(left, right);
            return make_pair(0,1);
        }
        if(dir1==1) {
            ans = max(ans,left+right+1);
            return make_pair(left+1,1);
        } else if (dir2==1) {
            ans = max(ans,left+right+1);
            return make_pair(right+1,1);
        }
        return make_pair(max(left,right)+1,0);
    }

    int amountOfTime(TreeNode* root, int start) {
        pii d = dfs(root,start);
        return ans;
    }
};
