class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),ans = -1, diff = INT_MAX;
        
        for(int i=0;i<n-2;i++){
            int s = i+1,e = n-1;
            if (i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            while(s<e){
                int sum = nums[i]+nums[s]+nums[e];
                if(abs(target-sum)<diff){
                    ans = sum;
                    diff = abs(target-sum);
                }
                if(sum<=target)s++;
                else e--;
            }
        }
        
        return ans;
    }
};

// the overall time complexity is O(n log n) + O(n^2), which simplifies to O(n^2).
// the space complexity of the solution is O(1) as it does not depend on the size of the input vector

// Problem Statement:
// The objective is to find the sum of three elements in the given vector nums such that the sum is closest to the target value. The solution should return the closest sum.

// Approach:

// Sorting:
// Sort the input vector nums in ascending order. Sorting is essential for efficient triplet detection.

// sort(nums.begin(), nums.end());
// Initialization:
// Initialize variables n as the size of the vector, ans as the current closest sum (initialized to -1), and diff as the absolute difference between the current closest sum and the target (initialized to INT_MAX).

// int n = nums.size(), ans = -1, diff = INT_MAX;
// Triplets Iteration:
// Iterate through the vector up to the third-to-last element (n - 2), denoted by i.
// Skip duplicate values of nums[i] to avoid redundant triplets.

// for (int i = 0; i < n - 2; i++) {
//     if (i != 0 && nums[i] == nums[i - 1]) {
//         continue;
//     }
// Two-Pointer Technique:
// Initialize two pointers, s (start) and e (end), to the next (i + 1) and last (n - 1) elements, respectively.

// int s = i + 1, e = n - 1;
// Triplet Sum Calculation:
// Calculate the sum of the triplet (nums[i] + nums[s] + nums[e]).
// If the absolute difference between the target and the current sum is less than the current difference (diff), update ans and diff.
// Adjust pointers based on the comparison of the sum with the target.

// int sum = nums[i] + nums[s] + nums[e];
// if (abs(target - sum) < diff) {
//     ans = sum;
//     diff = abs(target - sum);
// }
// if (sum <= target) s++;
// else e--;
// Return Result:
// The final result is the closest sum (ans) to the target.

// return ans;
// Example:
// Let's consider the input vector nums = [-1, 2, 1, -4] and target = 1:

// After sorting: [-4, -1, 1, 2]
// Iterating through triplets (i):
// For i = -4: s = -1, e = 2, triplet [-4, -1, 2] with a sum of -3.
// For i = -1: Skip duplicate.
// For i = 1: s = 1, e = 2, triplet [-1, 1, 2] with a sum of 2.
// Result: 2, which is the closest sum to the target 1.
