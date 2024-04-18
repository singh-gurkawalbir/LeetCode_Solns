# Approach 🛶
# Initialize two variables: islands to count the number of land cells encountered and neighbors to count the number of adjacent land cells.
# Iterate over each cell of the grid.
# For each land cell encountered, increment the islands count.
# Check the adjacent cells (up and left) and increment the neighbors count accordingly.
# Finally, return the total perimeter count using the formula islands * 4 - neighbors * 2.
# Complexity Analysis 📊
# Time complexity: O(N×M)O(N \times M)O(N×M), where NNN is the number of rows and MMM is the number of columns in the grid.
# Space complexity: O(1)O(1)O(1).

class Solution:
  def islandPerimeter(self, grid: List[List[int]]) -> int:
    m = len(grid)
    n = len(grid[0])

    islands = 0
    neighbors = 0

    for i in range(m):
      for j in range(n):
        if grid[i][j] == 1:
          islands += 1
          if i + 1 < m and grid[i + 1][j] == 1:
            neighbors += 1
          if j + 1 < n and grid[i][j + 1] == 1:
            neighbors += 1

    return islands * 4 - neighbors * 2


# #############         OR            # #############
# Iterative Approach with Counting Borders:
# In this method, we iterate through each cell of the grid. For every cell that represents land (denoted by 1), we initially assume it contributes 4 units to the perimeter. Then, we adjust this count based on the neighboring cells.

# For each land cell (grid[r][c] == 1), add 4 to the perimeter count since the cell has four potential sides.
# Check the left neighbor (grid[r][c-1]) and the top neighbor (grid[r-1][c]). If either of these neighbors is also land (1), it means the shared side between the current cell and its neighbor is internal to the island and should not contribute to the perimeter. Therefore, we subtract 2 from the perimeter count for each such shared side.
# By iterating over all cells and adjusting the perimeter count accordingly, we can efficiently compute the total perimeter of the entire island.

class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        perimeter = 0
        rows, cols = len(grid), len(grid[0])
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    perimeter += 4
                    if r > 0 and grid[r-1][c] == 1:
                        perimeter -= 2
                    if c > 0 and grid[r][c-1] == 1:
                        perimeter -= 2
                        
        return perimeter
