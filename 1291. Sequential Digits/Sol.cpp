class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;

        for (int i = 1; i <= 9; i++) {
            int num = i;

            for (int j = i + 1; j <= 9; j++) {
                num = num * 10 + j;

                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }

        std::sort(result.begin(), result.end());
        return result;
    }
};
// The problem asks us to find all integers within a given range that have sequential digits. A sequential digit is defined as a number in which each digit is one more than the previous digit. To solve this problem, we can systematically generate all possible sequential digits within the given range and filter out the valid ones.

// Approach
// Initialize an empty list result to store the sequential digits within the given range.

// Iterate through all possible starting digits from 1 to 9 (inclusive). For each starting digit, create a number by appending the subsequent digits in a nested loop.

// Check if the generated number is within the given range [low, high]. If it is, add the number to the result list.

// After both loops are complete, return the sorted result list.

// Complexity
// Time complexity: $$O(1)$$

// Space complexity:$$O(1)$$
