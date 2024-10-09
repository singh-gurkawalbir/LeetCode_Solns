#include <string>
#include <vector>
#include <climits>  // for INT_MAX

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) {
            return ""; // Edge case: If one of the strings is empty, return empty string
        }
        
        vector<int> map(128, 0); // Frequency map for characters (ASCII size 128)
        int left = 0, right = 0;  // Sliding window pointers
        int count = t.length();   // Number of characters in t to match
        int min_len = INT_MAX;    // Length of the minimum window
        int start = 0;            // Starting index of the minimum window
        
        // Fill the map with frequency of characters in string t
        for (char c : t) {
            map[c]++;
        }

        // Traverse the string s with the sliding window technique
        while (right < s.length()) {
            // If the character at 'right' is part of t, decrease the count
            if (map[s[right]] > 0) {
                count--;
            }
            // Decrease frequency of the current character in the map
            map[s[right]]--;
            right++;

            // When count == 0, we have a valid window
            while (count == 0) {
                // Update the minimum window size if needed
                if (right - left < min_len) {
                    min_len = right - left;
                    start = left;
                }

                // Try to shrink the window from the left
                map[s[left]]++;
                if (map[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }

        // If no valid window found, return empty string
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};

// Let's walk through an example using the minWindow function from the C++ solution provided above.
// Example:

//     Input:

//     cpp

//     s = "ADOBECODEBANC"
//     t = "ABC"

//     We need to find the smallest substring in s that contains all the characters of t.

// Dry Run:

//     Initial Setup:
//         s = "ADOBECODEBANC"
//         t = "ABC"
//         We initialize map to store the frequency of characters in t:

//     map['A'] = 1, map['B'] = 1, map['C'] = 1
//     count = 3  // the number of characters in t
//     left = 0, right = 0, min_len = INT_MAX, start = 0

// First iteration (right = 0, 'A'):

//     s[right] = 'A', and map['A'] is positive, so we decrement count:
//     count = 2
//     map['A'] = 0

//     Move right to 1.

// Second iteration (right = 1, 'D'):

//     s[right] = 'D' is not in t, so we just decrement map['D']:
//     map['D'] = -1

//     count remains 2.
//     Move right to 2.

// Third iteration (right = 2, 'O'):

//     s[right] = 'O' is not in t, so we decrement map['O']:
//     map['O'] = -1

//     count remains 2.
//     Move right to 3.

// Fourth iteration (right = 3, 'B'):

//     s[right] = 'B', and map['B'] is positive, so we decrement count:
//     count = 1
//     map['B'] = 0

//     Move right to 4.

// Fifth iteration (right = 4, 'E'):
//     s[right] = 'E' is not in t, so we decrement map['E']:
//     map['E'] = -1

//     count remains 1.
//     Move right to 5.

// Sixth iteration (right = 5, 'C'):

//     s[right] = 'C', and map['C'] is positive, so we decrement count:
//     count = 0  // We've now found all characters of t in the window
//     map['C'] = 0

//     Now that count == 0, we have a valid window: "ADOBEC".
//     The current window length is right - left = 6 - 0 = 6, so we update min_len = 6 and start = 0.

// Now, shrink the window from the left:

//     s[left] = 'A', so we increment map['A']:
//         map['A'] = 1
//         count = 1  // Now we no longer have all characters of t

//         Move left to 1, and continue expanding right.

//     Continue expanding and shrinking:
//         The process continues as we slide the window through s, ultimately finding the smallest valid window "BANC" with length 4 starting at index 9.

// Final Output:

//     The smallest window is "BANC" with length 4.
//     Return: "BANC".
