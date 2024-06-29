class Solution {
public:
    int dfs(int node,int parent,vector<int> adj[],vector<bool>& hasApple){
        int time=0;
        for(auto &i:adj[node]){
            if(i!=parent)
                time+=dfs(i,node,adj,hasApple);
        }
        return (time||hasApple[node])? time+=2:0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto &i:edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=dfs(0,-1,adj,hasApple);
        return ans==0?ans:ans-2; 
    }
};

int dfs(int node, int parent, vector<int> adj[], vector<bool>& hasApple) {
// int dfs(...): Declares a function named dfs which returns an integer.
// int node: The current node being visited.
// int parent: The parent node of the current node (used to avoid backtracking).
// vector<int> adj[]: An array of vectors representing the adjacency list of the tree.
// vector<bool>& hasApple: A reference to a boolean vector indicating which nodes have apples.
int time = 0;
// int time = 0; Initializes a counter time to 0, which will keep track of the time required to collect apples in the subtree rooted at the current node.
for (auto &i : adj[node]) {
    if (i != parent)
        time += dfs(i, node, adj, hasApple);
}
// for (auto &i : adj[node]): Iterates over each child of the current node.
// if (i != parent): Checks if the child node is not the parent node to avoid backtracking.
// time += dfs(i, node, adj, hasApple); Recursively calls dfs for each child and accumulates the time returned from the subtree.
return (time || hasApple[node]) ? time += 2 : 0;
// return (time || hasApple[node]) ? time += 2 : 0;
// If there are apples in the subtree (i.e., time > 0) or the current node has an apple (hasApple[node] == true), adds 2 to the time (to account for the round trip to this node) and returns the updated time.
// Otherwise, returns 0 indicating no additional time is needed for this subtree.
int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
// int minTime(...): Declares a function named minTime which returns an integer.
// int n: The number of nodes in the tree.
// vector<vector<int>>& edges: A reference to a list of edges, where each edge is represented by a pair of nodes.
// vector<bool>& hasApple: A reference to a boolean vector indicating which nodes have apples.

vector<int> adj[n];
for (auto &i : edges) {
    int u = i[0], v = i[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// vector<int> adj[n]; Initializes an array of vectors for the adjacency list with n nodes.
// for (auto &i : edges): Iterates over each edge.
// int u = i[0], v = i[1]; Extracts the nodes connected by the edge.
// adj[u].push_back(v); adj[v].push_back(u); Adds each edge to the adjacency list in both directions to represent an undirected tree.
int ans = dfs(0, -1, adj, hasApple);
return ans == 0 ? ans : ans - 2;
// int ans = dfs(0, -1, adj, hasApple); Calls the dfs function starting from the root node (0) with an initial parent of -1, and stores the total time required in ans.
// return ans == 0 ? ans : ans - 2; If ans is 0 (indicating no apples were found), returns 0. Otherwise, subtracts 2 from ans to adjust for the initial call which added an extra 2 for the root node.

// Example
// Consider the following tree with 7 nodes and the following edges:

// edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
// And the following hasApple array indicating which nodes have apples:

// hasApple = [false, false, true, false, true, true, false]
// Here is a visual representation of the tree:

//         0
//        / \
//       1   2
//      / \ / \
//     4  5 3  6
// Nodes 2, 4, and 5 have apples.

// Step-by-Step Execution
// Adjacency List Creation:
// The adjacency list representation of the tree is:

// adj = [
//     [1, 2],  // Node 0
//     [0, 4, 5],  // Node 1
//     [0, 3, 6],  // Node 2
//     [2],  // Node 3
//     [1],  // Node 4
//     [1],  // Node 5
//     [2]   // Node 6
// ]
// DFS Traversal and Calculation:

// Start at node 0 with parent -1.
// Traverse to node 1 with parent 0.
// Traverse to node 4 with parent 1.
// Node 4 is a leaf node and has an apple. Return 2 (time += 2).
// Traverse to node 5 with parent 1.
// Node 5 is a leaf node and has an apple. Return 2 (time += 2).
// Node 1 has collected apples from both 4 and 5. Return 4 (time += 4).
// Traverse to node 2 with parent 0.
// Traverse to node 3 with parent 2.
// Node 3 is a leaf node and does not have an apple. Return 0 (time remains same).
// Traverse to node 6 with parent 2.
// Node 6 is a leaf node and does not have an apple. Return 0 (time remains same).
// Node 2 has an apple itself and no apples from its children. Return 2 (time += 2).
// Node 0 has collected apples from nodes 1 and 2. Return 8 (time += 8).
// DFS Execution
// DFS at Node 0:
// DFS at Node 1:
// DFS at Node 4: Returns 2 (hasApple[4] is true).
// DFS at Node 5: Returns 2 (hasApple[5] is true).
// Returns 4 (time from node 4 and node 5).
// DFS at Node 2:
// DFS at Node 3: Returns 0 (hasApple[3] is false).
// DFS at Node 6: Returns 0 (hasApple[6] is false).
// Returns 2 (hasApple[2] is true).
// Returns 8 (total time from nodes 1 and 2).
