#include <vector>
#include <algorithm>
class Solution {
public:
    #define MOD 1000000007

    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        long long ans = 0;  // Use long long to avoid overflow in calculations
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            long long sum = static_cast<long long>(target) - arr[i];  // Ensure target is treated as long long

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                long long currentSum = static_cast<long long>(arr[left]) + arr[right]; // Use long long for safe addition

                if (currentSum < sum) {
                    left++;
                } else if (currentSum > sum) {
                    right--;
                } else {
                    int j = left;
                    int k = right;
                    int count1 = 0, count2 = 0;

                    while (j <= right && arr[j] == arr[left]) {
                        count1++;
                        j++;
                    }

                    if (j > right) {
                        // Calculate combinations
                        long long ans_here = static_cast<long long>(count1) * (count1 - 1) / 2;
                        ans = (ans + ans_here) % MOD;
                    } else {
                        while (k >= j && arr[k] == arr[right]) {
                            count2++;
                            k--;
                        }
                        ans = (ans + (static_cast<long long>(count1) * count2) % MOD) % MOD;
                    }

                    left = j;
                    right = k;
                }
            }
        }
        return static_cast<int>(ans); // Cast the final result back to int
    }
};

// To perform a dry run of the `threeSumMulti` function, let's consider a simple example with a small array and target. This will help illustrate how the algorithm works step-by-step.

// ### Example
// - **Array (`arr`)**: `[1, 2, 2, 3, 4]`
// - **Target**: `7`

// ### Dry Run Steps

// 1. **Initial Setup**:
//    - Sort the array: `[1, 2, 2, 3, 4]` (already sorted in this case).
//    - Initialize `ans = 0`.

// 2. **Outer Loop** (Iterate over each element as the first element of the triplet):
//    - **i = 0** (`arr[i] = 1`):
//      - Calculate `sum = target - arr[i] = 7 - 1 = 6`.
//      - Initialize `left = 1` and `right = 4`.

// 3. **Two-pointer Technique**:
//    - **First Iteration**:
//      - `arr[left] = 2`, `arr[right] = 4`.
//      - `arr[left] + arr[right] = 2 + 4 = 6` (equals `sum`).
//      - Count occurrences of `arr[left]` and `arr[right]`:
//        - `count1 = 2` (for `arr[left] = 2`), `count2 = 1` (for `arr[right] = 4`).
//      - Add `count1 * count2 = 2 * 1 = 2` to `ans`.
//      - Move `left` to 3 and `right` to 3.

//    - **Second Iteration**:
//      - `left` and `right` point to the same element, so break the loop.

// 4. **Next Iterations of Outer Loop**:
//    - **i = 1** (`arr[i] = 2`):
//      - Calculate `sum = 7 - 2 = 5`.
//      - Initialize `left = 2` and `right = 4`.
//      - **First Iteration**:
//        - `arr[left] = 2`, `arr[right] = 4`.
//        - `arr[left] + arr[right] = 2 + 4 = 6` (greater than `sum`), decrement `right`.
//      - **Second Iteration**:
//        - `arr[left] = 2`, `arr[right] = 3`.
//        - `arr[left] + arr[right] = 2 + 3 = 5` (equals `sum`).
//        - Count occurrences of `arr[left]` and `arr[right]`:
//          - `count1 = 1` (for `arr[left] = 2`), `count2 = 1` (for `arr[right] = 3`).
//        - Add `count1 * count2 = 1 * 1 = 1` to `ans`.
//        - Move `left` to 3 and `right` to 2.

// 5. **Continue with i = 2, 3, 4**:
//    - For `i = 2`, `sum = 5`, but `left` and `right` pointers do not find any valid pairs.
//    - For `i = 3`, `sum = 4`, but `left` and `right` pointers do not find any valid pairs.
//    - For `i = 4`, `left` would be out of bounds, so the loop ends.

// 6. **Final Result**:
//    - `ans = 3` (modulo operation is not needed here as the result is small).

// Thus, there are 3 ways to choose indices such that the sum of the elements at these indices equals the target.


// This C++ code snippet defines a class `Solution` with a method `threeSumMulti`, which calculates the number of ways to choose three indices \(i, j, k\) such that \(i < j < k\) and the sum of the elements at these indices in the array `arr` equals a given `target`. The result is returned modulo \(10^9 + 7\) (defined as `MOD`) to handle large numbers and prevent overflow.

// Here's a breakdown of the code:

// 1. **Includes and Definitions**:
//    - `#include <vector>` and `#include <algorithm>` are included for using the `vector` container and sorting functionality.
//    - `#define MOD 1000000007` defines a constant for the modulo operation.

// 2. **Function `threeSumMulti`**:
//    - **Parameters**: Takes a reference to a vector `arr` and an integer `target`.
//    - **Variables**:
//      - `n` stores the size of the array.
//      - `ans` is a `long long` variable to accumulate the count of valid triplets, using `long long` to avoid overflow.
//    - **Sorting**: The array `arr` is sorted to facilitate the two-pointer technique.
   
// 3. **Main Logic**:
//    - A loop iterates over each element `arr[i]` as a potential first element of the triplet.
//    - For each `i`, the target sum for the remaining two elements is calculated as `sum = target - arr[i]`.
//    - Two pointers, `left` and `right`, are initialized to find pairs in the subarray `arr[i+1]` to `arr[n-1]` that sum to `sum`.
//    - **Two-pointer Technique**:
//      - If the sum of elements at `left` and `right` is less than `sum`, increment `left`.
//      - If greater, decrement `right`.
//      - If equal, count the number of occurrences of `arr[left]` and `arr[right]`:
//        - If all elements between `left` and `right` are the same, calculate combinations using `count1 * (count1 - 1) / 2`.
//        - Otherwise, multiply the counts of `arr[left]` and `arr[right]` and add to `ans`.
//      - Move `left` and `right` pointers past the counted elements.
//    - **Modulo Operation**: The result is taken modulo `MOD` to ensure it fits within standard integer limits.

// 4. **Return**: The final result is cast back to `int` and returned.

// This algorithm efficiently counts the number of valid triplets using sorting and the two-pointer technique, ensuring that the solution is both time and space efficient.
