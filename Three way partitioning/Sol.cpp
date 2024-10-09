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
// Explanation of the Code:

// The provided C++ code is a solution to the three-way partitioning problem. This problem involves rearranging elements in an array such that:

//     All elements less than a are moved to the left.
//     All elements between a and b (inclusive) are in the middle.
//     All elements greater than b are moved to the right.

// Key Concepts:

// This problem can be thought of as a variation of the Dutch National Flag problem, where the array is divided into three parts:

//     Left part: elements smaller than a.
//     Middle part: elements between a and b (inclusive).
//     Right part: elements greater than b.

// Step-by-step Breakdown:

//     Initial Setup:
//         n = array.size(): Get the size of the array.
//         Two pointers are initialized:
//             i = 0: Points to the position where the next element smaller than a should be placed.
//             j = n - 1: Points to the position where the next element larger than b should be placed.
//         ind = 0: This is the index we use to traverse the array.

//     While Loop:
//         The loop runs as long as ind is within bounds (ind < n) and ensures that we haven't moved beyond the j pointer.

//     Checking Conditions:
//         If array[ind] < a:
//             The element at ind is smaller than a, so it needs to be moved to the left part of the array.
//             Swap array[ind] with array[i] (the current position of the i pointer).
//             Increment both ind and i since the swapped element is now correctly positioned, and we need to continue checking the rest of the array.
//         If array[ind] > b:
//             The element at ind is greater than b, so it needs to be moved to the right part of the array.
//             Swap array[ind] with array[j] (the current position of the j pointer).
//             Decrement j to adjust the boundary of the right part, but do not increment ind because the swapped element from the right side (now at ind) needs to be checked before moving on.
//         If a <= array[ind] <= b:
//             The element is within the range [a, b], so it’s already in the correct middle position.
//             Increment ind to check the next element.

//     Loop Termination:
//         The loop stops when ind exceeds j, meaning that all elements have been processed and partitioned into the correct sections.

// Time Complexity:

//     The algorithm processes each element in the array exactly once. Therefore, the time complexity is O(n), where n is the size of the array.

// Let’s perform a dry run of the three-way partition algorithm using the example:
// vector<int> array = {1, 3, 5, 2, 8, 6, 4, 7};
// int a = 3, b = 6;

// Initial Setup:

//     array = {1, 3, 5, 2, 8, 6, 4, 7}
//     a = 3, b = 6
//     i = 0 (points to where the next element smaller than a should go)
//     j = 7 (points to where the next element larger than b should go)
//     ind = 0 (iterator through the array)

// Step-by-step Dry Run:

//     Iteration 1 (ind = 0):
//         array[ind] = 1 (since 1 < a)
//         Swap array[ind] with array[i] (swap array[0] with array[0], so no change)
//         Increment both ind and i

//     Updated variables:
//         array = {1, 3, 5, 2, 8, 6, 4, 7}
//         i = 1, j = 7, ind = 1

//     Iteration 2 (ind = 1):
//         array[ind] = 3 (since 3 is between a and b)
//         No swap needed, just increment ind

//     Updated variables:
//         array = {1, 3, 5, 2, 8, 6, 4, 7}
//         i = 1, j = 7, ind = 2

//     Iteration 3 (ind = 2):
//         array[ind] = 5 (since 5 is between a and b)
//         No swap needed, just increment ind

//     Updated variables:
//         array = {1, 3, 5, 2, 8, 6, 4, 7}
//         i = 1, j = 7, ind = 3

//     Iteration 4 (ind = 3):
//         array[ind] = 2 (since 2 < a)
//         Swap array[ind] with array[i] (swap array[3] with array[1])
//         Increment both ind and i

//     Updated variables:
//         array = {1, 2, 5, 3, 8, 6, 4, 7}
//         i = 2, j = 7, ind = 4

//     Iteration 5 (ind = 4):
//         array[ind] = 8 (since 8 > b)
//         Swap array[ind] with array[j] (swap array[4] with array[7])
//         Decrement j (but don’t increment ind yet because the new array[4] needs to be checked)

//     Updated variables:
//         array = {1, 2, 5, 3, 7, 6, 4, 8}
//         i = 2, j = 6, ind = 4

//     Iteration 6 (ind = 4):
//         array[ind] = 7 (since 7 > b)
//         Swap array[ind] with array[j] (swap array[4] with array[6])
//         Decrement j (but don’t increment ind yet because the new array[4] needs to be checked)

//     Updated variables:
//         array = {1, 2, 5, 3, 4, 6, 7, 8}
//         i = 2, j = 5, ind = 4

//     Iteration 7 (ind = 4):
//         array[ind] = 4 (since a <= 4 <= b)
//         No swap needed, just increment ind

//     Updated variables:
//         array = {1, 2, 5, 3, 4, 6, 7, 8}
//         i = 2, j = 5, ind = 5

//     Iteration 8 (ind = 5):
//         array[ind] = 6 (since a <= 6 <= b)
//         No swap needed, just increment ind

//     Updated variables:
//         array = {1, 2, 5, 3, 4, 6, 7, 8}
//         i = 2, j = 5, ind = 6

// Final Array:

// After all iterations are complete, the final partitioned array is:

// {1, 2, 5, 3, 4, 6, 7, 8}

//     Left part (less than a = 3): {1, 2}
//     Middle part (between a and b = 6): {5, 3, 4, 6}
//     Right part (greater than b = 6): {7, 8}
