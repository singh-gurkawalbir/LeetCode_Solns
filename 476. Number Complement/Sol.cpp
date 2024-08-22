class Solution {
public:
    static int findComplement(int num) {
        if (num == 1) return 0;
        int ans = 0;
        for(int b = 0; num; b++, num >>= 1) { // num >>= 1 is equivalent to num /= 2
            ans += (1 - (num & 1)) << b; // (num & 1) extracts the last bit (0 or 1)
        }
        return ans;
    }
};

// Step-by-Step Breakdown
// Edge Case Check:
// if (num == 1) return 0;
// If num is 1, its binary representation is 1, and its complement is 0. The function immediately returns 0 for this case.
// Initialization:


// int ans = 0;
// ans is initialized to 0. It will store the final result, which is the binary complement of num.
// Loop Through Each Bit:


// for(int b = 0; num; b++, num >>= 1) {
// This loop iterates through each bit of num. The loop continues until num becomes 0.
// b is the position of the current bit being processed, starting from 0 (the least significant bit).
// num >>= 1 shifts the bits of num to the right by 1, effectively dividing num by 2. This is how the loop processes the next bit in each iteration.
// Processing Each Bit:


// ans += (1 - (num & 1)) << b;
// num & 1 extracts the last bit of num (which can be either 0 or 1).
// 1 - (num & 1) flips the bit. If num & 1 is 0, this expression results in 1; if num & 1 is 1, it results in 0.
// << b shifts the flipped bit to its correct position according to b. This ensures that the bit is placed in the corresponding position in ans.
// ans += ... adds this shifted bit to the result.
// Return the Result:


// return ans;
// After the loop has processed all bits of num, ans contains the binary complement of num. The function returns this value.
// Example Execution
// Let's take an example to understand how this works. Consider num = 5:

// 5 in binary: 101
// Complement in binary: 010
// Expected result: 2
// Loop Execution:

// First iteration (b = 0, num = 5 or 101):

// num & 1 = 1, so 1 - 1 = 0.
// 0 << 0 = 0.
// ans remains 0.
// num >>= 1 makes num = 2 (010 in binary).
// Second iteration (b = 1, num = 2 or 010):

// num & 1 = 0, so 1 - 0 = 1.
// 1 << 1 = 2.
// ans += 2, so ans = 2.
// num >>= 1 makes num = 1 (001 in binary).
// Third iteration (b = 2, num = 1 or 001):

// num & 1 = 1, so 1 - 1 = 0.
// 0 << 2 = 0.
// ans remains 2.
// num >>= 1 makes num = 0, and the loop ends.
// Final Output:

// The loop ends, and the function returns ans = 2, which is the complement of 5.
// Conclusion
// This method effectively computes the binary complement of an integer by iterating through each bit of the integer, flipping it, and accumulating the result in the correct binary position. The algorithm is efficient with a time complexity of O(log N), where N is the number being processed.
// Complexity
// Time complexity:
// O(max(log2(n),32))

// Space complexity:
// O(1)
