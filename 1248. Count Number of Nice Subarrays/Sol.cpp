// Intuition
// To solve the problem of counting the number of subarrays with exactly k odd numbers, we can use a sliding window approach. This method allows us to efficiently manage the window of elements in the array and count the number of valid subarrays without needing to recompute for each possible subarray.

// Approach
// Initialize Variables:

// ansCnt to store the final count of subarrays.
// cnt to store the count of valid subarrays ending at the current position.
// Two pointers i and j to maintain the sliding window.
// Sliding Window Expansion:

// Iterate over the array using the j pointer.
// If the current element is odd, decrement k and reset cnt to 0.
// Sliding Window Contraction:

// When k becomes 0, start contracting the window from the left (i pointer).
// For each element removed from the window, increment cnt.
// If the removed element is odd, increment k to continue expanding the window.
// Counting Valid Subarrays:

// Add cnt to ansCnt after each expansion step to count all valid subarrays ending at position j.
// Return Result:

// Return ansCnt as the final result.

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ansCnt = 0; // Final count of subarrays
        int cnt = 0;    // Count of valid subarrays ending at current position
        int i = 0, j = 0; // Two pointers for the sliding window

        while (j < nums.size()) {
            if (nums[j] % 2 != 0) { // If the current element is odd
                k--; // Decrement k as we have encountered an odd number
                cnt = 0; // Reset the count of valid subarrays ending at this position
            }
            
            while (k == 0) { // While we have exactly k odd numbers in the window
                if (nums[i] % 2 != 0) { // If the leftmost element of the window is odd
                    k++; // Increment k as we will remove this odd number
                }
                cnt++; // Increment count of valid subarrays ending at current position
                i++; // Move the left pointer of the window to the right
            }
            
            ansCnt += cnt; // Add the count of valid subarrays to the final answer
            j++; // Move the right pointer of the window to the right
        }

        return ansCnt; // Return the final count of subarrays with exactly k odd numbers
    }
};

