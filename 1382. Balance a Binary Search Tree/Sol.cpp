class Solution {
public:
    vector<int> vals;
    TreeNode* balanceBST(TreeNode* root) {
        trav(root);
        return buildBST(0,vals.size()-1);
    }
    void trav(TreeNode* root){
        if(root == nullptr)return;
        trav(root->left);
        vals.push_back(root->val);
        trav(root->right);
    }
    TreeNode* buildBST(int l, int r){
        if(l>r)return nullptr;
        int mid = (l+r)/2;
        TreeNode *root = new TreeNode(vals[mid]);
        root->left = buildBST(l,mid-1);
        root->right = buildBST(mid+1,r);
        return root;
    }
};

Complexity
// Time complexity:
// O(n)

// Space complexity:
// O(n)

// Use inorder inorder transveral to create a sorted int array. this can be done by different ways, iterative or recursive.
// Greedy method TreeNode* balanceBST(int l, int r) is defined recursively. It inserts values of arr[l..r] into a BST where 
// the root is new TreeNode(arr[m:=(l+r)/2]) & its left subtree balanceBST(l, m-1) & its right subtree balanceBST(m+1, r).
// Why does this Greedy method make this tree a BST? For x in arr, if x< arr[m] or x==arr[m] but index of x<m, it must be 
// inserted in the left subtree, otherwise in the right subtree.
// Why does this Greedy algorithm make this BST a balanced tree? The numbers of nodes in the left subtree balanceBST(l, m-1)
// & the number of the ones in the right subtree balanceBST(m+1, r) is differed at most 1.
