// Intuition
// The problem requires counting the number of arithmetic subsequences in the given array. A sequence is considered arithmetic if it has at least three elements, and the difference between any two consecutive elements is the same.
// Approach
// One way to solve this problem is to use dynamic programming. We can maintain a 2D array dp, where dp[i][j] represents the number of arithmetic subsequences ending at index i with a common difference of j. We can then iterate through the array, updating the dp array and counting the total number of arithmetic subsequences.
// Here's a step-by-step breakdown of the approach:
// 1. Initialize a variable total_count to 0, which will keep track of the total number of arithmetic subsequences.
// 2. Initialize a 2D array dp with dimensions n x n, where n is the length of the input array nums. Each element dp[i][j] will represent the number of arithmetic subsequences ending at index i with a common difference of j.
// 3. Iterate through the array nums with two nested loops:
// The outer loop (i) goes from 1 to n - 1.
// The inner loop (j) goes from 0 to i - 1.
// 4. For each pair of indices (i, j), calculate the common difference diff = nums[i] - nums[j].
// 5. Update dp[i][diff] by incrementing it by 1, indicating that we have found a new arithmetic subsequence ending at index i with a common difference of diff.
// 6. If there is an existing subsequence ending at index j with the common difference diff, extend it to form a longer subsequence ending at index i. Increment dp[i][diff] by the value of dp[j][diff].
// 7. Update the total_count by adding the value of dp[j][diff] to it.
// 8. After the loops, the total_count will contain the total number of arithmetic subsequences.
// Complexity
// Time complexity:
// $$O(n^2)$$ - The nested loops iterate through each pair of indices, leading to a quadratic time complexity.
// Space complexity:
// $$O(n^2)$$ - The 2D array dp has dimensions n x n, contributing to a quadratic space complexity.


class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        int total_count = 0;

        std::vector<std::unordered_map<int, int>> dp(n);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(nums[i]) - nums[j]; 

                if (diff > INT_MAX || diff < INT_MIN)
                    continue; 

                int diff_int = static_cast<int>(diff);

                dp[i][diff_int] += 1; 

                if (dp[j].count(diff_int)) {
                    dp[i][diff_int] += dp[j][diff_int];
                    total_count += dp[j][diff_int];
                }
            }
        }

        return total_count;
    }
};
