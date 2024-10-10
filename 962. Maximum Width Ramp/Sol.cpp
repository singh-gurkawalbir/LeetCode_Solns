class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> monoStack;
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (monoStack.empty() || nums[monoStack.top()] > nums[i]) {
                monoStack.push(i);
            }
        }
        for (int j = n - 1; j >= 0; --j) {
            while (!monoStack.empty() && nums[j] >= nums[monoStack.top()]) {
                result = max(result, j - monoStack.top());
                monoStack.pop();
            }
        }

        return result;
    }
};

// Intuition
// The problem asks to find the maximum width of a ramp (i, j) such that i < j and nums[i] <= nums[j]. A brute-force approach would be to check every possible pair, but this would be inefficient for large arrays. The key observation is that we can use a monotonic decreasing stack to store potential candidates for i, and then we iterate from the back of the array to find the largest possible j.

// Approach
// Monotonic Stack: We traverse the array and maintain a stack of indices where the values of nums are in decreasing order. This ensures that when we later iterate over the array from right to left, we can quickly find an index i such that nums[i] <= nums[j].

// Finding the Maximum Width: Starting from the rightmost index j, for each index, we pop from the stack until the top of the stack has an index i where nums[i] <= nums[j]. We then compute the width j - i and update the maximum width.

// Complexity
// Time Complexity: The time complexity is O(n) where n is the length of the nums array. We traverse the array twice: once to build the stack and once to compute the maximum width.
// Space Complexity: The space complexity is O(n) because we are using a stack to store the indices.
// This C++ code defines a class `Solution` with a public member function `maxWidthRamp`. The purpose of this function is to find the maximum width of a "ramp" in a given vector of integers `nums`. A "ramp" is defined as a pair of indices `(i, j)` such that `i < j` and `nums[i] <= nums[j]`. The width of the ramp is `j - i`.

// Here's a breakdown of the code:

// 1. **Initialization**:
//    - A `stack<int>` named `monoStack` is used to store indices of the vector `nums`.
//    - `n` is initialized to the size of `nums`.
//    - `result` is initialized to 0, which will store the maximum width of the ramp found.

// 2. **First Pass (Building the Monotonic Stack)**:
//    - The first `for` loop iterates over each index `i` from 0 to `n-1`.
//    - The stack `monoStack` is used to maintain a decreasing sequence of values from `nums` by storing their indices.
//    - If the stack is empty or the current number `nums[i]` is less than the number at the index on the top of the stack (`nums[monoStack.top()]`), the index `i` is pushed onto the stack.
//    - This ensures that `monoStack` contains indices of `nums` in a way that the values at these indices are in a non-increasing order.

// 3. **Second Pass (Finding the Maximum Width Ramp)**:
//    - The second `for` loop iterates over each index `j` from `n-1` to 0.
//    - The inner `while` loop checks if the current number `nums[j]` is greater than or equal to the number at the index on the top of the stack (`nums[monoStack.top()]`).
//    - If true, it calculates the width of the ramp as `j - monoStack.top()` and updates `result` with the maximum width found so far.
//    - The index at the top of the stack is then popped.
//    - This process continues until the stack is empty or the condition fails.

// 4. **Return Statement**:
//    - Finally, the function returns `result`, which contains the maximum width of the ramp found.

// The algorithm efficiently finds the maximum width ramp by using a monotonic stack to keep track of potential starting indices for ramps and then iterating backwards to find the widest possible ramp for each ending index. This approach ensures that the solution is found in linear time, O(n).

// To perform a dry run of the `maxWidthRamp` function, let's consider a sample input vector `nums`. We'll walk through the code step-by-step to see how it processes this input.

// ### Sample Input
// Let's use the following vector for our dry run:
// std::vector<int> nums = {6, 0, 8, 2, 1, 5};

// ### Dry Run Steps
// 1. **Initialization**:
//    - `monoStack` is initialized as an empty stack.
//    - `n` is set to 6 (the size of `nums`).
//    - `result` is initialized to 0.

// 2. **First Pass (Building the Monotonic Stack)**:
//    - **i = 0**: `nums[0] = 6`. The stack is empty, so push `0` onto `monoStack`. Now, `monoStack = [0]`.
//    - **i = 1**: `nums[1] = 0`. `nums[1] < nums[monoStack.top()]` (0 < 6), so push `1` onto `monoStack`. Now, `monoStack = [0, 1]`.
//    - **i = 2**: `nums[2] = 8`. `nums[2] >= nums[monoStack.top()]` (8 >= 0), so do not push `2`.
//    - **i = 3**: `nums[3] = 2`. `nums[3] >= nums[monoStack.top()]` (2 >= 0), so do not push `3`.
//    - **i = 4**: `nums[4] = 1`. `nums[4] >= nums[monoStack.top()]` (1 >= 0), so do not push `4`.
//    - **i = 5**: `nums[5] = 5`. `nums[5] >= nums[monoStack.top()]` (5 >= 0), so do not push `5`.

//    After the first pass, `monoStack = [0, 1]`.

// 3. **Second Pass (Finding the Maximum Width Ramp)**:
//    - **j = 5**: `nums[5] = 5`. `nums[5] >= nums[monoStack.top()]` (5 >= 0), calculate width: `5 - 1 = 4`. Update `result = 4`. Pop `1` from `monoStack`. Now, `monoStack = [0]`.
//    - **j = 4**: `nums[4] = 1`. `nums[4] >= nums[monoStack.top()]` (1 >= 0), calculate width: `4 - 0 = 4`. `result` remains 4. Pop `0` from `monoStack`. Now, `monoStack = []`.
//    - **j = 3**: `nums[3] = 2`. Stack is empty, so no further calculations.
//    - **j = 2**: `nums[2] = 8`. Stack is empty, so no further calculations.
//    - **j = 1**: `nums[1] = 0`. Stack is empty, so no further calculations.
//    - **j = 0**: `nums[0] = 6`. Stack is empty, so no further calculations.

// 4. **Return Statement**:
//    - The function returns `result`, which is 4.

// ### Conclusion
// The maximum width ramp found in the vector `nums = {6, 0, 8, 2, 1, 5}` is 4, corresponding to the indices `(1, 5)`.
        
