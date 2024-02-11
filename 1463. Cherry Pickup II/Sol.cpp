class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return dfs(grid, n, m, 0, 0, m - 1, dp);
    }

    int dfs(vector<vector<int>>& grid, int n, int m, int r, int col1, int col2, vector<vector<vector<int>>>& dp) {
        if (r < 0 || r >= n || col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) {
            return 0;
        }

        if (dp[r][col1][col2] != -1) {
            return dp[r][col1][col2];
        }

        int maxCherries = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newCol1 = col1 + i;
                int newCol2 = col2 + j;

                maxCherries = max(maxCherries, dfs(grid, n, m, r + 1, newCol1, newCol2, dp));
            }
        }

        int currCherry = (col1 == col2) ? grid[r][col1] : grid[r][col1] + grid[r][col2];

        dp[r][col1][col2] = currCherry + maxCherries;
        return dp[r][col1][col2];
    }
};

// Tips
// No cells have negative value.
// If both robot collied, then the value of the cell will be counted once.
// condition for collision (col1==col2).
// Approach
// Initialization:
// Initialize variables n and m representing the number of rows and columns in the grid, respectively.
// Create a 3D array dp of size [n][m][m] to memoize the results of subproblems. dp[r][col1][col2] will store the maximum number of cherries that can be picked starting from row r, with one picker at column col1 and the other picker at column col2.
// Depth-First Search (DFS) function:
// The DFS function dfs takes the grid, dimensions n and m, current row r, columns of both pickers col1 and col2, and the memoization array dp.
// Base case: If either picker goes out of bounds, return 0 (no cherries picked).
// Memoization: If the result for the current state (dp[r][col1][col2]) is already computed, return it.
// Explore all possible movements for both pickers (up, left, right):
// Recur for the next row and updated column positions.
// Update maxCherries with the maximum cherries collected among all movements.
// Calculate the cherries collected in the current cell (currCherry), considering if both pickers are in the same column or different columns.
// Store the result in dp[r][col1][col2] and return it.
// Cherry Picking:
// Start DFS from the top row (r = 0) with both pickers at the outermost columns (col1 = 0, col2 = m-1).
// The result of the DFS call will be the maximum cherries picked from the grid.
// Complexity
// Time complexity: O(n∗m∗m)O(n*m*m)O(n∗m∗m)
// Space complexity: O(n∗m∗m)O(n*m*m)O(n∗m∗m)
