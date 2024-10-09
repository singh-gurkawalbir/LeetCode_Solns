class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0; 
        int hi = nums.size() - 1; 
        int mid = 0; 

        while (mid <= hi) { 
            switch (nums[mid]) { 

            // If the element is 0 
            case 0: 
                swap(nums[lo++], nums[mid++]); 
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[hi--]); 
                break; 
            }
        }
        
    }
};

// This C++ code snippet is an implementation of the [Dutch National Flag problem](https://leetcode.com/problems/sort-colors/description/), which is used to sort an array containing three distinct values. In this specific case, the values are 0, 1, and 2, which represent colors in the problem statement. The goal is to sort the array such that all 0s come first, followed by all 1s, and then all 2s.

// Here's a breakdown of the code:

// 1. **Class Definition**: The code defines a class named `Solution` with a public member function `sortColors`.

// 2. **Function `sortColors`**: This function takes a reference to a vector of integers `nums` as its parameter. The vector contains only the integers 0, 1, and 2.

// 3. **Variable Initialization**:
//    - `lo` is initialized to 0. It represents the boundary for the next position of 0.
//    - `hi` is initialized to `nums.size() - 1`. It represents the boundary for the next position of 2.
//    - `mid` is initialized to 0. It is used to traverse the array.

// 4. **While Loop**: The loop continues as long as `mid` is less than or equal to `hi`.

// 5. **Switch Statement**: The switch statement checks the value of `nums[mid]` and performs actions based on its value:
//    - **Case 0**: If `nums[mid]` is 0, it swaps the elements at indices `lo` and `mid`, then increments both `lo` and `mid`. This places the 0 in the correct position and moves the `mid` pointer forward.
//    - **Case 1**: If `nums[mid]` is 1, it simply increments `mid` because 1s are already in the correct middle position.
//    - **Case 2**: If `nums[mid]` is 2, it swaps the elements at indices `mid` and `hi`, then decrements `hi`. This places the 2 in the correct position at the end of the array. The `mid` pointer is not incremented in this case because the swapped element at `mid` needs to be checked again.

// This algorithm efficiently sorts the array in a single pass with a time complexity of O(n) and a space complexity of O(1), making it optimal for this problem. 

// Let's perform a dry run of the `sortColors` function using an example input array. We'll use the array `[2, 0, 2, 1, 1, 0]` to illustrate how the algorithm works step-by-step.

// ### Initial Setup
// - `nums = [2, 0, 2, 1, 1, 0]`
// - `lo = 0`
// - `mid = 0`
// - `hi = 5` (since the array size is 6)

// ### Step-by-Step Execution

// 1. **First Iteration** (`mid = 0`):
//    - `nums[mid] = 2`
//    - Swap `nums[mid]` with `nums[hi]`: `[0, 0, 2, 1, 1, 2]`
//    - Decrement `hi`: `hi = 4`
//    - `mid` remains `0` because we need to check the new element at `mid`.

// 2. **Second Iteration** (`mid = 0`):
//    - `nums[mid] = 0`
//    - Swap `nums[lo]` with `nums[mid]`: `[0, 0, 2, 1, 1, 2]` (no change since `lo` and `mid` are the same)
//    - Increment `lo`: `lo = 1`
//    - Increment `mid`: `mid = 1`

// 3. **Third Iteration** (`mid = 1`):
//    - `nums[mid] = 0`
//    - Swap `nums[lo]` with `nums[mid]`: `[0, 0, 2, 1, 1, 2]` (no change since `lo` and `mid` are the same)
//    - Increment `lo`: `lo = 2`
//    - Increment `mid`: `mid = 2`

// 4. **Fourth Iteration** (`mid = 2`):
//    - `nums[mid] = 2`
//    - Swap `nums[mid]` with `nums[hi]`: `[0, 0, 1, 1, 2, 2]`
//    - Decrement `hi`: `hi = 3`
//    - `mid` remains `2` because we need to check the new element at `mid`.

// 5. **Fifth Iteration** (`mid = 2`):
//    - `nums[mid] = 1`
//    - Increment `mid`: `mid = 3`

// 6. **Sixth Iteration** (`mid = 3`):
//    - `nums[mid] = 1`
//    - Increment `mid`: `mid = 4`

// ### End of Loop
// - The loop ends because `mid` (4) is now greater than `hi` (3).

// ### Final Sorted Array
// - `nums = [0, 0, 1, 1, 2, 2]`

// The array is now sorted with all 0s at the beginning, followed by all 1s, and all 2s at the end. This dry run demonstrates how the algorithm efficiently sorts the array in a single pass.
