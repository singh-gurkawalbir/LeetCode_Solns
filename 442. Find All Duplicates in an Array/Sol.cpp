// Intuition

// The key observation is that each element in the input array nums has a corresponding index within the range [1, n]. 
// We can leverage this by using the array elements themselves as indices to mark their occurrences. In essence, we'll "flip the sign" at the index corresponding to each element.

// Approach

// Iterate through the nums array:

// For each element nums[i], calculate its absolute value (abs(nums[i])) to handle negative values.
// Use this value as the index (idx) to access the element at that position.
// Mark occurrences by negating the value at the idx-th index:

// If the value at nums[idx - 1] is already negative, it indicates a duplicate element encountered earlier (since it was previously negated). In this case, add the current element (idx) to the result vector.
// Otherwise, negate the value at nums[idx - 1]. This essentially marks the first occurrence of the element at idx.
// Return the result:

// After iterating through the entire array, the result vector will contain all the elements that appeared twice (identified by their negated indices).
// Time Complexity

// O(n): The loop iterates through the array once, visiting each element only once.
// Space Complexity

// O(1): Constant extra space is used for the result vector and temporary variables like i and idx.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int num =abs(nums[i]);
            int idx = num - 1;
            if(nums[idx] < 0)
                result.push_back(num);
            
            nums[idx] *= -1;
        }
        return result;
    }
};

// Let's perform a dry run of the given code with the provided test case nums = [4, 3, 2, 7, 8, 2, 3, 1]:

// Initialize an empty vector result to store duplicate elements.

// Set the size of the array nums to n.

// Loop through each element in nums:

// For the first iteration:
// Current element: nums[0] = 4
// Absolute value of the current element: num = abs(4) = 4
// Calculate the index: idx = num - 1 = 4 - 1 = 3
// Check if the element at index 3 (zero-based index) of nums is negative (indicating it has been encountered before):
// nums[3] is not negative (7 > 0)
// No duplicate, move to the next iteration.
// For the second iteration:
// Current element: nums[1] = 3
// Absolute value of the current element: num = abs(3) = 3
// Calculate the index: idx = num - 1 = 3 - 1 = 2
// Check if the element at index 2 of nums is negative:
// nums[2] is not negative (2 > 0)
// No duplicate, move to the next iteration.
// For the third iteration:
// Current element: nums[2] = 2
// Absolute value of the current element: num = abs(2) = 2
// Calculate the index: idx = num - 1 = 2 - 1 = 1
// Check if the element at index 1 of nums is negative:
// nums[1] is not negative (3 > 0)
// No duplicate, move to the next iteration.
// For the fourth iteration:
// Current element: nums[3] = 7
// Absolute value of the current element: num = abs(7) = 7
// Calculate the index: idx = num - 1 = 7 - 1 = 6
// Check if the element at index 6 of nums is negative:
// nums[6] is not negative (3 > 0)
// No duplicate, move to the next iteration.
// For the fifth iteration:
// Current element: nums[4] = 8
// Absolute value of the current element: num = abs(8) = 8
// Calculate the index: idx = num - 1 = 8 - 1 = 7
// Check if the element at index 7 of nums is negative:
// nums[7] is not negative (1 > 0)
// No duplicate, move to the next iteration.
// For the sixth iteration:
// Current element: nums[5] = 2
// Absolute value of the current element: num = abs(2) = 2
// Calculate the index: idx = num - 1 = 2 - 1 = 1
// Check if the element at index 1 of nums is negative:
// nums[1] is negative (-3 < 0)
// Duplicate found, push num (2) into result.
// Negate the element at index 1 of nums: nums[1] = -3
// For the seventh iteration:
// Current element: nums[6] = 3
// Absolute value of the current element: num = abs(3) = 3
// Calculate the index: idx = num - 1 = 3 - 1 = 2
// Check if the element at index 2 of nums is negative:
// nums[2] is negative (-2 < 0)
// Duplicate found, push num (3) into result.
// Negate the element at index 2 of nums: nums[2] = -2
// For the eighth iteration:
// Current element: nums[7] = 1
// Absolute value of the current element: num = abs(1) = 1
// Calculate the index: idx = num - 1 = 1 - 1 = 0
// Check if the element at index 0 of nums is negative:
// nums[0] is not negative (4 > 0)
// No duplicate, move to the next iteration.
// Return the vector result, which contains the duplicate elements found during the iterations: [2, 3].

// So, the output of the function findDuplicates(nums) is [2, 3].
