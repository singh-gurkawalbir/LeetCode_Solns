// Intuition
// We use a two pointers technique to find two non-negative integers a and b such that a^2 + b^2 = c

// Approach
// The solution initializes two pointers, left = 0 and right = sqrt(c).
// We employ this approach by adjusting these pointers based on whether the current sum left^2 + right^2 equals, exceeds, or falls short of c.
// This adjustment continues until left exceeds right, indicating no valid pair was found.
// If a pair satisfies the given condition during the process, the function returns true, else returns false.
// Complexity
// Time complexity: O(sqrt(c))

// Space complexity: O(1)

var judgeSquareSum = function(c) {
    let left = 0, right = Math.floor(Math.sqrt(c));
    while (left <= right) {
        let sum = left * left + right * right;
        if (sum === c) return true;
        else if (sum > c) right--;
        else left++;
    }
    return false;
};
