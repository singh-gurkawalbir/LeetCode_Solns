// Let's break down the code step by step:

// The code starts by initializing some variables:

// "m" represents the number of rows in the matrix.
// "n" represents the number of columns in the matrix.
// "res" is the variable that will store the final result, i.e., the number of submatrices with the target sum.
// The code then enters a nested loop structure to iterate through all possible submatrices:

// The outer loop, controlled by the variable "l", iterates over the columns of the matrix.
// The inner loop, controlled by the variable "r", iterates over the columns starting from "l" to the end of the matrix.
// Inside the nested loops, the code performs the following operations:

// It initializes an array called "sums" with size 105 and sets all elements to 0. This array will store the cumulative sum of elements in each row of the submatrix.
// It then iterates over the rows of the matrix using the variable "i" and updates the "sums" array by adding the corresponding element from the current column.
// Next, it iterates over the rows again using the variable "i" and calculates the sum of elements in each possible submatrix.
// For each submatrix sum, it checks if it is equal to the target value. If it is, it increments the "res" variable by 1.
// After the nested loops finish executing, the code returns the final result stored in the "res" variable.
  
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;

        for (int l = 0; l < n; ++l) {
            int sums[105] = {0};
            for (int r = l; r < n; ++r) {
                for (int i = 0; i < m; ++i) {
                    sums[i] += matrix[i][r];
                }
                for (int i = 0; i < m; ++i) {
                    int sum = 0;
                    for (int j = i; j < m; ++j) {
                        sum += sums[j];
                        if (sum == target) {
                            ++res;
                        }
                    }
                }
            }
        }

        return res;
    }
};
