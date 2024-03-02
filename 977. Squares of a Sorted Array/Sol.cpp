class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        start, end = 0, n - 1
        for i in range(n - 1, -1, -1):
            if abs(nums[start]) >= abs(nums[end]):
                ans[i] = nums[start] * nums[start]
                start += 1
            else:
                ans[i] = nums[end] * nums[end]
                end -= 1
        return ans

// range(n - 1, -1, -1): The range() function generates a sequence of numbers. In this case, it starts from n - 1, which is the index of the last element in the sequence, and ends at -1, 
// which is one less than the first index (essentially stopping at index 0). The third argument -1 specifies the step size, indicating that the sequence should be decremented by 1 in each step,
// effectively iterating in reverse.

// This Python snippet defines a class `Solution` with a method `sortedSquares`. The method takes a list of integers `nums` as input and returns a list of integers. 

// Here's a step-by-step explanation of the method:
// 1. It calculates the length of the input list `nums` and initializes a new list `ans` with zeros of the same length.
// 2. It sets two pointers `start` and `end` to the beginning and end of the list respectively.
// 3. It iterates over the list `nums` in reverse order using a for loop.
// 4. Inside the loop, it compares the absolute values of the elements at the `start` and `end` pointers.
// 5. If the absolute value of the element at `start` is greater than or equal to the absolute value of the element at `end`, it squares the element at `start` and assigns it to the corresponding index in the `ans` list, then increments the `start` pointer.
// 6. If the absolute value of the element at `end` is greater, it squares the element at `end` and assigns it to the corresponding index in the `ans` list, then decrements the `end` pointer.
// 7. Finally, it returns the `ans` list containing the squared values of the input list `nums` in sorted order.

// This method essentially squares the elements of the input list `nums`, sorts them in non-decreasing order of their absolute values, and returns the resulting list.

// Time complexity:
// O(n)

// Space complexity:
// O(n)

