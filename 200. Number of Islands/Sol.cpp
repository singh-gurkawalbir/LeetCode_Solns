class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return numIslands;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '0'; // mark as visited
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
};

// Let's follow the execution:

// Start with numIslands = 0.
// Iterate over each cell in the grid.
// Encounter '1' at grid[0][0], increment numIslands to 1, and call dfs(grid, 0, 0).
// Inside dfs, mark grid[0][0] as '0', then call dfs(grid, 1, 0), dfs(grid, 0, 1).
// Recursively, '1's connected to grid[0][0] are marked as '0's.
// Back to the loop in numIslands, continue iteration.
// Encounter '1' at grid[2][2], increment numIslands to 2, and call dfs(grid, 2, 2).
// '1's connected to grid[2][2] are marked as '0's.
// Back to the loop in numIslands, continue iteration.
// Encounter '1' at grid[3][3], increment numIslands to 3, and call dfs(grid, 3, 3).
// '1's connected to grid[3][3] are marked as '0's.
// No more '1's left in the grid, return numIslands = 3.
// So, the output is 3, which matches the expected output.
