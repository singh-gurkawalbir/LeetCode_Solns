class Solution {
int i = 0;
public:
    string reverseParentheses(string s) {
        return helper(s);
    }

    string helper(string& s) {
        string result;

        while (i < s.length()) {
            if (s[i] == ')') {
                i++;
                reverse(result.begin(), result.end());
                return result;
            } else if (s[i] == '(') {
                i++;
                string st = helper(s);
                result += st;
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};

// Intuition
// The given problem is to reverse substrings enclosed within parentheses, starting from the innermost ones. The nested nature of parentheses suggests using a recursive approach or a stack-based approach to handle the reversals in the correct order. The idea is to treat the problem by breaking it down recursively: whenever we encounter an opening parenthesis, we recursively solve for the substring until the corresponding closing parenthesis, reverse the substring, and then continue.

// Approach
// Initialization: Convert the string s into a character array for easy manipulation. Initialize a helper function that will perform the recursive operations.
// Recursive Helper Function:
// Use a StringBuilder to construct the result string.
// Iterate through the characters of the string:
// If a closing parenthesis ) is encountered, reverse the constructed string and return it to the previous level of recursion.
// If an opening parenthesis ( is encountered, increment the index and recursively call the helper function to process the substring inside the parentheses. Append the reversed substring to the current StringBuilder.
// For any other character, simply append it to the StringBuilder.
// Return the Result: After processing the entire string, return the result as a string.
// Complexity
// Time complexity: O(n), where n is the length of the string. Each character is processed once, and reversing the substrings is linear in the total number of characters processed.
// Space complexity: O(n) for the recursion stack in the worst case of fully nested parentheses and for the StringBuilder used to construct the result.
// Step By Step Explanation
// Example
// Input: (u(love)i)
// Output: iloveu
// Explanation:

// Reverse the substring "love" to "evol".
// The string becomes (uevoli).
// Reverse the entire string inside the parentheses to get iloveu.
// Steps to Solve
// Step	Index	Current Character	 Action	            Current Substring	Depth	Result
// 1	      0	       (	             Start new recursion		              1	
// 2	      1	       u	             Append u	               u	          1	
// 3	      2	       (	             Start new recursion	   u	          2	
// 4	      3	       l	             Append l	               l	          2	
// 5	      4	       o	             Append o	               lo           2	
// 6	      5	       v	             Append v	               lov	        2	
// 7	      6	       e	             Append e	               love	        2	
// 8	      7	       )	             End recursion, reverse	 evol	        1	   u + evol
// 9	      8	       i	             Append i	               uevoli	      1	
// 10	    9	       )	             End recursion, reverse	 iloveu	      0	
// Final Result
// After completing the traversal and reversing at the appropriate steps, the final result is iloveu.

