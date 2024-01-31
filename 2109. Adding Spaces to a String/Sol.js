var addSpaces = function (s, spaces) {
    let prev = 0, res = '';
    for (let curr of spaces) {
        res += s.substring(prev, curr);
        res += ' ';
        prev = curr;
    }
    return res + s.substring(prev)
}
// Problem Statement:
// The goal is to insert spaces at specified indices in the input string s, as defined by the spaces array. The modified string should be returned.

// Approach:

// Initialization:
// Initialize variables prev to 0 (representing the starting index) and an empty string res to store the result.

// let prev = 0, res = '';
// Iterating through Space Indices:
// Iterate through each index curr in the spaces array.
// Concatenate the substring of s from prev to curr to the result string res.
// Append a space character to res.
// Update prev to the current index curr.

// for (let curr of spaces) {
//     res += s.substring(prev, curr);
//     res += ' ';
//     prev = curr;
// }
// Final Concatenation:
// Concatenate the remaining substring of s from the last prev value to the end of the string.

// return res + s.substring(prev);
// Return Result:
// The final result is the modified string with spaces inserted at specified indices.

// return res + s.substring(prev);
// Example:
// Let's consider the input string s = "EnjoyYourCoffee" and spaces = [5, 9]:

// Initialization:

// prev = 0, res = ''.
// Iterating through Space Indices:

// For curr = 5:
// Concatenate the substring from prev to curr (i.e., "Enjoy") to res.
// Append a space character to res.
// Update prev to curr.
// Continuing Iteration:

// For curr = 9:
// Concatenate the substring from prev to curr (i.e., "Your") to res.
// Append a space character to res.
// Update prev to curr.
// Final Concatenation:

// Concatenate the remaining substring from the last prev value to the end of the string (i.e., "Coffee").
// Result:

// The final result is "Enjoy Your Coffee".


// Time Complexity:
// Let's analyze the time complexity of the provided JavaScript solution:

// Iteration through spaces array:

// The loop that iterates through the spaces array has a time complexity of O(k), where k is the number of elements in the spaces array.
// String Concatenation:

// String concatenation using += within the loop takes O(m) time, where m is the length of the substring being concatenated.
// Final Concatenation:

// The final concatenation of the remaining substring takes O(n) time, where n is the length of the original string s.
// Therefore, the overall time complexity is O(k * m) + O(n), which simplifies to O(k * m).

// Space Complexity:
// The space complexity is determined by the additional space used by variables prev and res.

// prev:

// The prev variable requires constant space.
// res:

// The res variable stores the modified string. The maximum space it occupies is the length of the original string s plus the number of spaces to be inserted.
// Therefore, the overall space complexity is O(n + k).

// In summary, the time complexity is O(k * m) + O(n), and the space complexity is O(n + k).
