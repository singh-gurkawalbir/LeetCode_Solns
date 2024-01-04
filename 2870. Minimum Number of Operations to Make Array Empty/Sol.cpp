class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        // Create an unordered_map to store the frequency of each unique element
        std::unordered_map<int, int> um;
        int count = 0;

        // Step 1: Build the frequency map
        for (int x : nums) {
            um[x]++;
        }

        // Step 2: Iterate through the frequency map
        for (auto x : um) {
            int freq = x.second;

            // Check if a single element cannot be used in any operation
            if (freq == 1) {
                return -1;
            }

            // Step 3: Calculate the number of operations for the current element
            count += freq / 3;

            // If there are remaining elements, add one more operation to the count
            if (freq % 3) {
                count++;
            }
        }

        // Step 4: Return the total count, representing the minimum operations required
        return count;
    }
};
