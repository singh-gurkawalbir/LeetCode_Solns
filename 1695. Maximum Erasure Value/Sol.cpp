class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        // Declare a map to keep track of the frequency of each number in the current subarray.
        unordered_map<int, int> mp;
        
        // Initialize variables to store the maximum sum of unique subarray, current sum, and two pointers.
        int maxValue = 0; // Maximum sum of unique subarray found so far.
        int sum = 0;      // Current sum of the subarray.
        int i = 0;        // Left pointer for the sliding window.
        int j = 0;        // Right pointer for the sliding window.
        int n = nums.size(); // Size of the input array.

        // Iterate with the right pointer j through the entire array.
        while(j < n)
        {
            // Add the current number to the sum and increment its frequency in the map.
            sum += nums[j];
            mp[nums[j]]++;

            // If the frequency of the current number exceeds 1, we have duplicates.
            // We need to adjust the left pointer i to make the subarray unique.
            while(mp[nums[j]] > 1)
            {
                // Decrease the frequency of the number at the left pointer i and subtract its value from the sum.
                mp[nums[i]]--;
                sum -= nums[i];
                i++; // Move the left pointer to the right.
            }

            // Update maxValue if the current sum is greater than the previously recorded maximum sum.
            maxValue = max(sum, maxValue);
            
            // Move the right pointer to the next position.
            j++;
        }

        // Return the maximum sum of the unique subarray found.
        return maxValue;
    }
};

Time complexity: O(n)
Space complexity: O(n)
