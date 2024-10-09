class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for (auto c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0)
                    open--;
                else
                    close++;
            }
        }
        return open + close;
    }
};
// This C++ code is designed to solve a problem where you need to find the minimum number of parentheses that must be added to make a string of parentheses valid. A valid parentheses string means every opening parenthesis ( has a corresponding closing parenthesis ) and they are correctly nested.

// Code Breakdown:
// Function Name: minAddToMakeValid
// Takes a string s as input (which consists of only ( and )).
// Returns an integer representing the minimum number of parentheses that need to be added to make the string valid.
// Variables:
// open: Tracks unmatched opening parentheses (.
// close: Tracks unmatched closing parentheses ).
// Logic:
// Loop through the string:
// For each character c in the string s:
// If the character is (:
// Increment the open counter because there is an unmatched opening parenthesis.
// If the character is ):
// If there is an unmatched opening parenthesis (open > 0):
// Decrement the open counter to match this closing parenthesis.
// If there is no unmatched opening parenthesis (open == 0):
// Increment the close counter because there is an unmatched closing parenthesis.
// Return Value:
// After the loop, the number of unmatched opening parentheses is stored in open, and the number of unmatched closing parentheses is stored in close.
// The total number of parentheses that need to be added to make the string valid is the sum of open and close.
// Example:
// Input: "())"

// After processing:
// open = 1 (1 unmatched opening parenthesis)
// close = 1 (1 unmatched closing parenthesis)
// The function returns 1 + 1 = 2.
// Input: "((("

// After processing:
// open = 3 (3 unmatched opening parentheses)
// close = 0
// The function returns 3 + 0 = 3.
// Time Complexity:
// The time complexity is O(n), where n is the length of the string s, because the loop iterates through the string once.
// Space Complexity:
// The space complexity is  O(1) as the function only uses a few integer variables.
