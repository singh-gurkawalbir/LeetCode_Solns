# Initialization:
# Initialize sum to keep track of the cumulative sum of elements encountered so far.
# Initialize count to store the count of subarrays with a sum equal to k.
# Create a HashMap map to store the frequency of cumulative sums encountered so far. Initialize it with one entry {0, 1}, denoting that a sum of 0 has occurred once.
# Iterating through the array:
# Iterate through the nums array from left to right.
# At each step, update the sum by adding the current element nums[i].
# Calculating the remainder:
# Calculate rem, which is the remainder needed to make the current sum equal to k. It's calculated as sum - k.
# Checking for subarrays:
# Check if rem exists in the map. If it does, it means there exists a subarray ending at the current index whose sum is k. Increment count by the frequency of rem in the map.
# Updating the frequency map:
# Update the frequency of the current sum in the map by either incrementing its count if it already exists or adding a new entry with a count of 1.
# Return the count:
# After iterating through the entire array, return the final value of count, which represents the total count of subarrays with a sum equal to k.
# Complexity
# Time complexity: O(N)
# Space complexity: O(N)


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sum = 0
        count = 0
        map = defaultdict(int)
        map[0] = 1

        for num in nums:
            sum += num
            rem = sum - k

            if rem in map:
                count += map[rem]
            map[sum] += 1

        return count
