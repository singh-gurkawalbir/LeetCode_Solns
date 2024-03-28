// Intuition:

// The problem asks us to find the longest subarray where each element's frequency is less than or equal to k. We can solve this efficiently using a sliding window technique with a frequency tracker.

// Here's the thought process:

// We can imagine a window that slides across the array, keeping track of the elements within it.
// As the window moves, we maintain a dictionary (unordered_map) to store the frequencies of each element encountered so far within the window.
// A good subarray is one where all element frequencies are less than or equal to k.
// We'll use two pointers, i and j, to define the window's boundaries (i for the start and j for the end).
// We'll iterate through the array, expanding the window to the right using j.
// While expanding, we'll update the frequency map for the newly added element.
// If the current window becomes invalid (any element's frequency exceeds k), we'll shrink it from the left side using i, removing elements and updating their frequencies until it becomes valid again.
// At each step, we'll keep track of the maximum length of a valid subarray encountered so far.
// Approach:

// Sliding Window with Frequency Tracker:

// Use a sliding window approach to iterate through the array.
// Maintain a dictionary (unordered_map) named freq to track the frequency of each element encountered within the window.
// Two pointers, i and j, define the window's boundaries (left and right endpoints).
// Initialize i, j, and ans (maximum length) to 0.
// Iterate and Expand Window:

// While j (right pointer) is less than the array's length (n):
// Add the current element (nums[j]) to the frequency map freq. Increment its count if it already exists.
// Update j to expand the window to the right.
// Shrink Window if Invalid:

// While any element's frequency in freq is greater than k:
// Remove the leftmost element (nums[i]) from the window by decrementing its frequency in freq. If its frequency becomes zero, remove it from the map completely.
// Update i to shrink the window from the left.
// Update Maximum Length:

// After potentially shrinking the window, check if the current window is valid (all frequencies <= k).
// If the current window is valid, calculate its length (j - i + 1) and update ans (maximum length) if it's greater than the current maximum.
// Return Maximum Length:

// After iterating through the entire array, return the value of ans which holds the length of the longest good subarray found.
// Time Complexity:

// O(n): The algorithm iterates through the array once using a single loop with j as the iterator. Inside the loop, the potential shrinking operation (while loop) 
// also has a worst-case time complexity of O(n) in case all elements need to be removed. However, on average, it's expected to be much less than n. Overall, the time complexity remains linear.
// Space Complexity:

// O(n): The freq dictionary stores the frequencies of elements in the current window. In the worst case, it might hold all unique elements in the array, leading to a space complexity of O(n).
// Code :

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n = nums.size();
        int ans = 0;
        int i=0,j=0;
        while(j < n){
            freq[nums[j]]++;
            while(freq[nums[j]] > k){
                freq[nums[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
