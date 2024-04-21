// Intuition:
// The problem asks whether there exists a valid path from a given source vertex to a destination vertex in a bi-directional graph. We can approach this problem by traversing the graph using depth-first search (DFS) or breadth-first search (BFS) algorithms to explore all possible paths from the source to the destination.

// Approach:
// Initialize: Create a boolean array visited of size n to keep track of visited vertices. Mark the source vertex as visited initially.
// Traversal Loop: Use a while loop that continues until there are no more changes in the visited vertices (flag remains false).
// Check Edges: Within each iteration of the loop, iterate through the edges array. For each edge, if one vertex is visited and the other is not, mark both vertices as visited and set flag to true.
// Destination Check: After updating the visited array, check if the destination vertex is marked as visited. If so, return true as a valid path exists.
// Return: If the while loop completes without finding a valid path to the destination, return false.
// Complexity Analysis:
// Time Complexity: The time complexity is O(n + E), where n is the number of vertices and E is the number of edges. This is because we traverse each vertex once and iterate through the edges array to update visited vertices.
// Space Complexity: The space complexity is O(n) for the visited array and O(E) for storing the edges information, leading to a total space complexity of O(n + E).
// Overall, this solution efficiently determines the existence of a valid path from the source to the destination in the given bi-directional graph.

#include <vector>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (n == 1) return true;
        vector<bool> visited(n, false);
        visited[source] = true;
        bool flag = true;
        while (flag) {
            flag = false;
            for (const auto& edge : edges) {
                if (visited[edge[0]] != visited[edge[1]]) {
                    visited[edge[0]] = true;
                    visited[edge[1]] = true;
                    flag = true;
                }
                if (visited[destination]) return true;
            }
        }
        return false;
    }
};
// Dry Run:

// Initially, visited = [False, False, False, False, False, False].
// We start at source = 0, so visited[0] is set to True.
// Since none of the edges lead directly to vertex 5 (the destination), the loop iterates through the edges:
// Edge [0, 1]: Vertex 0 is already visited, vertex 1 is not. We update visited = [True, True, False, False, False, False] and set flag = True.
// Edge [0, 2]: Similar to the previous edge, update visited = [True, True, True, False, False, False] and flag = True.
// Edges [3, 5], [5, 4], and [4, 3] don't connect to any unvisited neighbors so they don't change the visited array or the flag.
// After the first iteration of the loop, visited = [True, True, True, False, False, False], and flag remains True because new vertices were visited.
// The loop continues iterating through the edges in subsequent passes, but none of the edges lead to unvisited vertices. Eventually, after multiple iterations, the flag won't be changed to True since no progress is made (no new vertices are visited), and the loop terminates.

// Output:

// Since the loop finishes without reaching the destination vertex (i.e., visited[destination] is not True), the function returns False, indicating there's no path from source (vertex 0) to destination (vertex 5) in this graph.




