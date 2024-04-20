# Intuition
# This kind of grid land/water problem usually can be solved via graph traversal, but is there a way to make it more space efficient than BFS or DFS? 🤔

# Approach
# The main insight is that the farmland groups must always be a rectangle - we can use this property to just track till where the rectangle expands.

# For each cell that is a 1, we check if this cell is the start of a new rectangle. This is done by checking the cells above and to the left of the current cell.

# Once a starting cell is identified, we expand down and right to capture the max possible extent of the rectangle, and add that to our farmlands.

# Complexity
# Time complexity:
# O(rows*cols)

# Space complexity:
# O(1) - no visited marking is required either.

class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        rows, cols = len(land), len(land[0])
        farmlands = []
        
        for i in range(rows):
            for j in range(cols):
                # check if (i, j) is the start of a new farmland rectangle
                if land[i][j] == 1 and (i == 0 or land[i - 1][j] == 0) and (j == 0 or land[i][j - 1] == 0):
                    bottom_row = i
                    right_col = j

                    # expand down to find the bottom boundary 
                    while bottom_row + 1 < rows and land[bottom_row + 1][j] == 1:
                        bottom_row += 1
                    # expand right to find the right boundary 
                    while right_col + 1 < cols and land[i][right_col + 1] == 1:
                        right_col += 1

                    farmlands.append([i, j, bottom_row, right_col])
                    
        return farmlands

# Given the input land = [[1,0,0],[0,1,1],[0,1,1]], let's follow the execution:

# Initialize farmlands list to store the coordinates of farmland rectangles.
# Iterate through each cell of the land grid.
# At (0, 0), we have land[0][0] = 1. This is the start of a new farmland rectangle as it's not surrounded by any other farmland. We expand down and right to find the boundaries.
# bottom_row becomes 0, right_col becomes 0.
# Farmland rectangle coordinates are [0, 0, 0, 0].
# At (0, 1) and (0, 2), we don't find any new farmland rectangles.
# At (1, 0), (1, 1), and (1, 2), we don't find any new farmland rectangles.
# At (2, 0), (2, 1), and (2, 2), we find a new farmland rectangle starting at (1, 1). We expand down and right to find the boundaries.
# bottom_row becomes 2, right_col becomes 2.
# Farmland rectangle coordinates are [1, 1, 2, 2].
# No more cells left to check. We return farmlands = [[0, 0, 0, 0], [1, 1, 2, 2]].
# So, the output is [[0, 0, 0, 0], [1, 1, 2, 2]], which matches the expected output.







