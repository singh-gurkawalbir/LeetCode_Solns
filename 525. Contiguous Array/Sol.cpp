// vIntuition
// To find the maximum length of a contiguous subarray with an equal number of 0s and 1s, we can use the concept of prefix sum. Whenever we encounter a 0, we decrement the sum by 1, and whenever we encounter a 1, we increment the sum by 1. If the prefix sum at two indices is the same, it means that the number of 0s and 1s between those two indices is the same. We store these prefix sums along with their indices in a hash map. Then, for each prefix sum encountered, we check if we have seen this sum before. If so, it means that the subarray between the current index and the index where this sum was last encountered has an equal number of 0s and 1s. We calculate the length of this subarray and update the maximum length accordingly.

// Approach
// Initialize a hash map to store prefix sums along with their indices.
// Initialize variables for sum, maximum subarray length, and iterate through the input array.
// For each element in the array, update the sum according to the element (decrement by 1 for 0, increment by 1 for 1).
// If the sum becomes zero at any index, update the maximum length to the current index plus one.
// If the sum is encountered again (which means there is a subarray with equal 0s and 1s between the previous occurrence and the current index), update the maximum length if the current subarray length is greater than the previously stored maximum length.
// Return the maximum subarray length.
// Complexity Analysis
// Time complexity: (O(n)), where (n) is the length of the input array. We traverse the array only once.
// Space complexity: (O(n)), in the worst case, when all elements are distinct and the sum becomes distinct for each index, we would need to store all prefix sums in the hash map.
Code
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int subArray_length = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i] == 0 ? -1 : 1; 
            if (sum == 0) {
                subArray_length = i + 1;
            } else if (mp.find(sum) != mp.end()) {
                subArray_length = max(subArray_length, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return subArray_length;
    }
};
// Dry Run on Test Case
// Let's dry run the provided test case [0,0,1,0,0,0,1,1]:

// Sure, let's do a step-by-step dry run of the provided code with the input [0,0,1,0,0,0,1,1].

// Step 1: Initialization

// n is set to 8 (size of input vector).
// mp is an empty unordered map to store sum and corresponding indices.
// sum is initialized to 0 to track cumulative sum.
// subArray_length is initialized to 0 to store the maximum length of subarray with equal number of 0s and 1s.
// Step 2: Loop through the array

// Iteration 1: i = 0
// nums[0] is 0, so sum becomes -1.
// mp becomes { -1: 0 }.
// Iteration 2: i = 1
// nums[1] is 0, so sum becomes -2.
// mp becomes { -1: 0, -2: 1 }.
// Iteration 3: i = 2
// nums[2] is 1, so sum becomes -1.
// mp becomes { -1: 0, -2: 1, -1: 2 }.
// Iteration 4: i = 3
// nums[3] is 0, so sum becomes -2.
// Since -2 is already in mp, update subArray_length to 3 - 1 = 2.
// Iteration 5: i = 4
// nums[4] is 0, so sum becomes -3.
// mp becomes { -1: 0, -2: 1, -1: 2, -3: 4 }.
// Iteration 6: i = 5
// nums[5] is 0, so sum becomes -4.
// mp becomes { -1: 0, -2: 1, -1: 2, -3: 4, -4: 5 }.
// Iteration 7: i = 6
// nums[6] is 1, so sum becomes -3.
// Since -3 is already in mp, update subArray_length to 6 - 2 = 4.
// Iteration 8: i = 7
// nums[7] is 1, so sum becomes -2.
// Since -2 is already in mp, update subArray_length to 7 - 1 = 6.
// Step 3: Return subArray_length

// The maximum length of the subarray with equal number of 0s and 1s is 4.
// So, the code returns 4 as the maximum length of such subarray.
