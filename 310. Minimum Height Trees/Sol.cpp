// Approach
// i) Create an adjacency list
// ii) Traverse the tree to identify the leaf nodes. Leaf nodes are nodes with only one adjacent node.
// iii) Remove the leaf nodes from the tree iteratively until only one or two nodes are left. This process involves removing nodes that become leaf nodes after each iteration.
// iv) After trimming, the remaining node(s) will be the root(s) of the MHTs. If there is only one remaining node, it will be the root of the single MHT. If there are two remaining nodes, they will be the roots of the MHTs.

// Concept:
// The root of the minimum height tree (MHT), also known as the "center of gravity," can consist of more than two nodes, depending on the tree's structure and the diameter.

// Case I :
// Odd Diameter:
// -> If the diameter of the tree is odd, the center of gravity will be a single node.
// -> This single node is the deepest node along the longest path in the tree.

// Case II :
// Even Diameter:
// -> If the diameter of the tree is even, the center of gravity will consist of two adjacent nodes.
// -> These two nodes are the midpoints of the longest path(s) in the tree.
// -> In this case, the center of gravity represents the midpoint(s) of the longest path(s).

// Complexity
// Time complexity: O(V+E)
// Space complexity: O(V+E)
Code

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0) {
            vector<int> tmp;
            tmp.push_back(0);
            return tmp;
        }
        unordered_map<int, list<int>> adj;

        // creating adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> leaves; // Stores current leaf nodes

        // Initialize leaves with nodes having only 1 adjacent node
        for(auto& d : adj) {
            if(d.second.size() == 1) {
                leaves.push_back(d.first);
            }
        }

        // answer can consist of max. 2 nodes (Reason explained above)
        while(n > 2) {
            vector<int> new_leaves;

            // remove current leaves
            n -= leaves.size(); 

            for(int leaf : leaves) {
                // get the only neighbour of leaf
                int neighbor = adj[leaf].front(); 
                // remove leaf from neighbour's adjacency list
                adj[neighbor].remove(leaf); 
                
                // if the adjacent node becomes a leaf node after removal, add it to the queue.
                if(adj[neighbor].size() == 1) {
                    new_leaves.push_back(neighbor); 
                }
            }
            
            // update current no of leaf nodes
            leaves = new_leaves; 
        }

        return leaves;
    }
};
