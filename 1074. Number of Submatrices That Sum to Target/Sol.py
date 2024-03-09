# This Python snippet defines a class `Solution` with a method `numSubmatrixSumTarget`. The method takes a matrix (2D list of integers) and a target integer as input and returns an integer. 

# Here's a breakdown of what the method does:
# 1. It initializes variables `n` and `m` to the number of rows and columns in the matrix respectively.
# 2. It initializes a variable `ans` to 0.
# 3. It iterates over each row in the matrix and calculates the cumulative sum of each row by adding the current element to the previous element in the row.
# 4. It then iterates over all possible submatrices by considering all possible start and end columns.
# 5. For each submatrix, it maintains a `lookup` dictionary to store the cumulative sum and its frequency.
# 6. It calculates the cumulative sum of the submatrix by subtracting the elements based on the start and end columns.
# 7. If the difference between the cumulative sum and the target exists in the `lookup` dictionary, it increments the answer by the frequency of that difference.
# 8. It updates the `lookup` dictionary with the current cumulative sum frequency.
# 9. Finally, it returns the total count of submatrices that sum up to the target.

# This method essentially solves a problem related to finding the number of submatrices within a given matrix that sum up to a specific target value.

# What is the significance of the `lookup` dictionary in this method? What purpose does it serve in the context of finding submatrices that sum up to a target value? How does the method handle overlapping submatrices during the iteration process?

# The `lookup` dictionary in the `numSubmatrixSumTarget` method serves a crucial role in efficiently finding submatrices that sum up to a target value. 

# 1. **Significance of the `lookup` dictionary**:
#    - It stores the cumulative sum of elements within submatrices and their frequencies. This allows the method to keep track of the sum of 
# elements encountered so far and how many times each sum has occurred.
#    - By using the `lookup` dictionary, the method can quickly check if a specific cumulative sum (difference between the current sum and the
#  target) has been seen before and how many times it has occurred. This information helps in counting the number of submatrices that sum up to the target.

# 2. **Purpose in finding submatrices that sum up to a target value**:
#    - The `lookup` dictionary enables the method to efficiently identify submatrices with the desired sum without recalculating the sum 
# for each submatrix. It optimizes the process by storing and updating cumulative sums as the method iterates through the matrix.

# 3. **Handling overlapping submatrices**:
#    - The method handles overlapping submatrices by considering all possible start and end columns for each submatrix. By iterating through 
# the matrix and updating the `lookup` dictionary for each submatrix, it ensures that overlapping submatrices are correctly counted without 
# redundant calculations. This approach allows the method to cover all possible submatrices and accurately determine the count of submatrices 
# that sum up to the target value.

# The time complexity of the `numSubmatrixSumTarget` method can be analyzed as follows:

# 1. Calculating Cumulative Sums: 
#    - The initial loop that calculates the cumulative sum of each row takes O(m) time for each row, where m is the 
# number of columns. Since this loop iterates over all rows, the total time complexity for this step is O(n * m), where n is the number of rows.

# 2. Iterating Over Submatrices:
#    - The nested loops that iterate over all possible submatrices take O(m^2) time, where m is the number of columns.

# 3. Updating Lookup Dictionary:
#    - Within the submatrix iteration, updating the `lookup` dictionary and checking for the target sum takes O(n) time, 
# where n is the number of rows.

# Therefore, the overall time complexity of the method is O(n * m * m), where n is the number of rows and m is the number
#  of columns.

# Regarding space complexity:
# - The space complexity is O(n) for storing the `lookup` dictionary, where n is the number of rows in the matrix. This 
# is because the dictionary stores the cumulative sum frequencies for each row.

# In summary, the time complexity of the method is O(n * m^2), and the space complexity is O(n).

class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        n=len(matrix)
        m=len(matrix[0])
        ans=0
        for r in matrix:
            for i in range(1,len(r)):
                r[i]+=r[i-1]
        for start in range(m):
            for end in range(start,m):
                lookup=defaultdict(int)
                cumsum=0
                lookup[0]=1
                for k in range(n):
                    cumsum+=matrix[k][end] - (matrix[k][start-1] if start !=0 else 0)
                    if cumsum -target in lookup:
                        ans+=lookup[cumsum-target]
                    lookup[cumsum]+=1
        return ans                        
