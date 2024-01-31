class Solution {
public:
     vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while (nums[j] == nums[j - 1] && j < k)
                    {
                        j++;
                    }
                    while (nums[k] == nums[k + 1] && k > j)
                    {
                        k--;
                    }
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return result;
    }
};

// Problem Statement:
// The goal is to find all unique triplets in the given vector nums that sum up to zero (0). The solution needs to return a vector of vectors containing these triplets.

// Approach:

// Sorting:
// Sort the input vector nums in ascending order. Sorting is essential for efficient triplet detection.

// sort(nums.begin(), nums.end());
// Iterating through Triplets:
// Iterate through the sorted vector nums up to the third-to-last element (size() - 2), denoted by i.
// Skip duplicate values of nums[i] to avoid redundant triplets.

// for (int i = 0; i < nums.size() - 2; i++) {
//     if (i != 0 && nums[i] == nums[i - 1]) {
//         continue;
//     }
// Two-Pointer Technique:
// Initialize two pointers, j and k, to the next (i + 1) and last (nums.size() - 1) elements, respectively.
// Use a while loop to check for triplets until j is less than k.

// int j = i + 1, k = nums.size() - 1;
// while (j < k) {
// Triplet Sum Calculation:
// Calculate the sum of the triplet (nums[i] + nums[j] + nums[k]).
// If the sum is zero, add the triplet to the result vector.
// Move both pointers (j and k) towards the center.
// Skip duplicate values to avoid redundant triplets.

// int sum = nums[i] + nums[j] + nums[k];
// if (sum == 0) {
//     result.push_back({nums[i], nums[j], nums[k]});
//     j++, k--;

//     // Skip duplicates
//     while (nums[j] == nums[j - 1] && j < k) {
//         j++;
//     }
//     while (nums[k] == nums[k + 1] && k > j) {
//         k--;
//     }
// }
// Adjusting Pointers based on Sum:
// If the sum is less than zero, increment j.
// If the sum is greater than zero, decrement k.

// else if (sum < 0) {
//     j++;
// }
// else {
//     k--;
// }
// Return Result:
// The final result is a vector of vectors containing unique triplets that sum up to zero.

// return result;
// Example:
// Let's consider the input vector nums = [-1, 0, 1, 2, -1, -4]:

// After sorting: [-4, -1, -1, 0, 1, 2]
// Iterating through triplets (i):
// For i = -4: j = -1, k = 2, triplet [-4, -1, 2] found.
// For i = -1: j = -1, k = 0, triplet [-1, -1, 2] found.
// For i = -1: Skip duplicate.
// For i = 0: No triplet found.
// For i = 1: j = 0, k = 2, triplet [-1, 0, 1] found.
// Result: [[-4, -1, 2], [-1, -1, 2], [-1, 0, 1]]
