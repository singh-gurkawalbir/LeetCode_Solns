# Intuition
# One way to approach this problem is to use a greedy strategy. We can keep track of the minimum and maximum number of open parentheses that must be matched and see if it's possible to match all the parentheses in the string. We'll use two variables leftMin and leftMax to represent the minimum and maximum number of open parentheses respectively.
# Approach
# 1. Initialize leftMin and leftMax to 0.
# 2. Iterate through each character in the string s.
# 3. If the character is '(', increment both leftMin and leftMax by 1.
# 4. If the character is ')', decrement both leftMin and leftMax by 1.
# 5. If the character is '*', decrement leftMin by 1 and increment leftMax by 1.
# 6. If leftMax becomes negative at any point, return False since it means there are more closing parentheses than opening ones.
# 7. If leftMin becomes negative, reset it to 0 since we can't have negative open parentheses count.
# 8. After iterating through the string, check if leftMin is 0. If it is, return True; otherwise, return False.
# Time complexity:
# O(n), where n is the length of the input string s. We iterate through the string once.
# Space complexity:
# O(1), as we only use a constant amount of extra space for variables.

class Solution:
    def checkValidString(self, s: str) -> bool:
        leftMin, leftMax = 0, 0

        for c in s:
            if c == "(":
                leftMin, leftMax = leftMin + 1, leftMax + 1
            elif c == ")":
                leftMin, leftMax = leftMin - 1, leftMax - 1
            else:
                leftMin, leftMax = leftMin - 1, leftMax + 1
            if leftMax < 0:
                return False
            if leftMin < 0:
                leftMin = 0
        return leftMin == 0
