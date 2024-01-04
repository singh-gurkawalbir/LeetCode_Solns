
// Intuition
// The goal is to find the minimum number of operations to empty the given array by either removing two or three elements with equal values at a time. The key insight is that any number of operations can only be performed on elements with the same value. Therefore, we need to determine how many operations can be performed for each unique element in the array.

// Approach
// Use an unordered_map (um) to store the frequency of each unique element in the array.
// Iterate through the elements of the array and update the frequency in the unordered_map.
// Iterate through the unordered_map and for each unique element:
// Check if its frequency is 1. If so, return -1 because a single element cannot be used in any operation.
// Calculate the number of operations that can be performed with the current frequency. Add the result to the total count.
// If there are remaining elements (frequency % 3), add one more operation to the count.
// Return the total count, which represents the minimum number of operations required to empty the array.
// This approach ensures that operations are performed optimally on elements with the same value, minimizing the total number of operations needed to make the array empty.
// Complexity
// Time complexity:
// The time complexity is O(N), where N is the number of elements in the input array nums. In the worst case, we iterate through each element of the array once to build the frequency map, and then iterate through the unique elements in the frequency map.

// Space complexity:
// The space complexity is O(U), where U is the number of unique elements in the input array nums. We use an unordered_map (um) to store the frequency of each unique element. In the worst case, the number of unique elements is proportional to the size of the input array.

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int curr, prev = 0;
        int n = bank.size();    // Number of rows in the bank
        int m = bank[0].size(); // Number of columns in the bank
        int ans = 0;           // Variable to store the total number of laser beams

        // Iterate through each row of the bank
        for (int i = 0; i < n; i++) {
            curr = 0; // Reset the current count of security devices for each row

            // Iterate through each column of the current row
            for (int j = 0; j < m; j++) {
                if (bank[i][j] == '1') {
                    curr++; // Count the number of security devices in the current row
                }
            }

            // If there are security devices in the current row
            if (curr != 0) {
                // Accumulate the product of current count and previous count
                ans += curr * prev;
                prev = curr; // Update the previous count for the next iteration
            }
        }

        // Return the total number of laser beams
        return ans;
    }
};

