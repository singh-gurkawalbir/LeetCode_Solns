class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        count = {0: 1}
        curr_sum = 0
        total_subarrays = 0
        
        for num in nums:
            curr_sum += num
            if curr_sum - goal in count:
                total_subarrays += count[curr_sum - goal]
            count[curr_sum] = count.get(curr_sum, 0) + 1

        return total_subarrays

# Initialization:

# count = {0: 1}: This initializes a dictionary called count with one key-value pair: 0 as the key and 1 as the value. This represents that there is one subarray whose sum is 0.
# curr_sum = 0: This initializes a variable curr_sum to keep track of the cumulative sum of elements encountered so far.
# total_subarrays = 0: This initializes a variable total_subarrays to keep track of the total count of subarrays whose sum is equal to the goal.
# Iterating through nums:

# The code iterates through each element num in the list nums.
# Calculating Cumulative Sum:

# curr_sum += num: This adds the current element num to the curr_sum, updating the cumulative sum.
# Checking for Subarrays with the Desired Sum:

# if curr_sum - goal in count: This checks if the difference between the current cumulative sum curr_sum and the goal is present in the count dictionary.
# If it is, it means there exists a subarray whose sum is equal to the goal.
# Updating total_subarrays:

# total_subarrays += count[curr_sum - goal]: If there is such a subarray, the code increments total_subarrays by the count of subarrays found in count[curr_sum - goal].
# Updating Count Dictionary:

# count[curr_sum] = count.get(curr_sum, 0) + 1: This updates the count dictionary by incrementing the count of the current cumulative sum curr_sum. If curr_sum is already present in count, it increments its count by 1. Otherwise, it initializes its count to 1.
# Returning the Result:

# return total_subarrays: Finally, the code returns the total count of subarrays whose sum equals the goal.

# Initial State:

# count = {0: 1}
# curr_sum = 0
# total_subarrays = 0
# Iteration 1:

# num = 1
# curr_sum = 1
# curr_sum - goal = 1 - 2 = -1 (not in count)
# count[curr_sum] = count.get(1, 0) + 1 = 0 + 1 = 1
# count = {0: 1, 1: 1}
# Iteration 2:

# num = 0
# curr_sum = 1 + 0 = 1
# curr_sum - goal = 1 - 2 = -1 (not in count)
# count[curr_sum] = count.get(1, 0) + 1 = 1 + 1 = 2
# count = {0: 1, 1: 2}
# Iteration 3:

# num = 1
# curr_sum = 1 + 1 = 2
# curr_sum - goal = 2 - 2 = 0 (in count)
# total_subarrays += count[0] = 0 + 1 = 1
# count[curr_sum] = count.get(2, 0) + 1 = 0 + 1 = 1
# count = {0: 1, 1: 2, 2: 1}
# Iteration 4:

# num = 0
# curr_sum = 2 + 0 = 2
# curr_sum - goal = 2 - 2 = 0 (in count)
# total_subarrays += count[0]) = 1 + 1 = 2
# count[curr_sum] = count.get(2, 0) + 1 = 1 + 1 = 2
# count = {0: 1, 1: 2, 2: 2}
# Iteration 5:

# num = 1
# curr_sum = 2 + 1 = 3
# curr_sum - goal = 3 - 2 = 1 (in count)
# total_subarrays += count[1] = 2 + 2 = 4
# count[curr_sum] = count.get(3, 0) + 1 = 0 + 1 = 1
# count = {0: 1, 1: 2, 2: 2, 3: 1}
# Final State:

# total_subarrays = 4
# Return Value: 4

# return total_subarrays = 4
# The function numSubarraysWithSum returns 4, indicating there are 4 subarrays with a sum equal to the goal
