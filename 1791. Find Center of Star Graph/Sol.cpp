class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }   
        return edges[0][1];
    }
};

// We first note that the given input is always valid, indicating it forms a star graph where there exists exactly one central node connected by n - 1 edges.
// The center node appears in each edge, so we can simply compare the nodes of the first and second edges to identify the common node, which serves as the center.
// Complexity:

// Time Complexity : O(1)
// Space Complexity : O(1)
