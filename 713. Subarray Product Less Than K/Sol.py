# product /= nums[left]: Divides the value of product by the value of nums[left] and assigns the result back to product.
# product //= nums[left]: Divides the value of product by the value of nums[left], takes the integer part of the result, and assigns it back to product.

# Intuition:

# Imagine a sliding window traversing the array. We keep track of the product of elements within the window. If the product becomes greater than or 
# equal to k, we need to shrink the window from the left side until the product becomes less than k. This process ensures that all subarrays 
# considered have a product strictly less than k.

# Approach:

# Initialization: Set left and right pointers to 0, product to 1 (initial empty subarray), and count to 0 (to store final subarray count).
# Sliding Window:
# While right hasn't reached the end (right < n):
# Expand the window: Multiply product by the current element nums[right].
# Shrink the window (if necessary):
# While product is greater than or equal to k:
# Divide product by the leftmost element nums[left] and increment left. This shrinks the window and reduces the product.
# Count subarrays:
# Add 1 + (right - left) to count. This accounts for:
# 1: The single-element subarray ending at right.
# (right - left): The number of contiguous subarrays within the current window (excluding elements already removed in the inner loop).
# Increment right to move the window one step forward.
# Return Result:
# Return the final count representing the total number of subarrays with product less than k.
# Time Complexity:

# Best Case: O(n) if k is very small (product never exceeds k) or very large (no window shrinking needed).
# Average Case: O(n) due to the efficient sliding window approach. In each iteration, either right is incremented (constant time) or left is incremented (constant time) in the inner loop. This leads to a maximum of n iterations overall.
# Worst Case: O(n^2) if elements in nums are very close to 1 and k is just slightly larger than the product of all elements. In this scenario, the window might shrink very slowly, leading to more iterations in the worst case.
# Space Complexity:

# O(1) as we use constant extra space (left, right, product, and count) independent of the input size.
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0

        left, right, product, count = 0, 0, 1, 0
        n = len(nums)

        while right < n:
            product *= nums[right]
            while product >= k:
                product //= nums[left]
                left += 1
            count += 1 + (right - left)
            right += 1

        return count
# Dry Run:

# Example 1: nums = [10, 5, 2, 6], k = 100

# Initialize variables:

# left = 0, right = 0: Pointers for the sliding window.
# product = 1: Running product of the elements within the window.
# count = 0: Counter to track the number of subarrays with product less than k.
# n = 4: Length of the input array nums.
# Start looping over the array nums:

# For the first iteration (right = 0):

# Update product: product *= nums[0] = 1 * 10 = 10
# product is less than k, so no action taken within the inner while loop.
# Update count: count = 0 + 1 + (0 - 0) = 1
# Increment right: right = 1
# For the second iteration (right = 1):

# Update product: product *= nums[1] = 10 * 5 = 50
# product is less than k, so no action taken within the inner while loop.
# Update count: count = 1 + 1 + (1 - 0) = 3
# Increment right: right = 2
# For the third iteration (right = 2):

# Update product: product *= nums[2] = 50 * 2 = 100
# product becomes equal to k, so enter the inner while loop.
# Update product: product //= nums[0] = 100 // 10 = 10
# Increment left: left = 1
# Update count: count = 3 + 1 + (2 - 1) = 5
# Increment right: right = 3
# For the fourth iteration (right = 3):

# Update product: product *= nums[3] = 10 * 6 = 60
# product is less than k, so no action taken within the inner while loop.
# Update count: count = 5 + 1 + (3 - 1) = 8
# Increment right: right = 4
# End of loop. Return count = 8.

# So, the output of the function numSubarrayProductLessThanK(nums, k) with nums = [10, 5, 2, 6] and k = 100 is 8.

# k <= 0: The problem definition states that k should be strictly positive. If k is less than or equal to 0, no subarray will have a product less than k. In the code, we handle this by returning 0 if k <= 1.
# Improved Code (Addressing Integer Overflow)
