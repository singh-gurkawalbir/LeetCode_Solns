// Frequency Counting:

// Two vectors (freq1 and freq2) are used to count the frequency of each letter in word1 and word2.
// freq1[i] stores the count of the i-th letter in the English alphabet in word1, and similarly for freq2.
// Checking Presence of Characters:

// Iterate over each character in the alphabet.
// If a character is present in one word and not in the other (or vice versa), return false.
// This ensures that both words contain the same set of characters.
// Sorting Frequencies:

// Sort the frequency vectors (freq1 and freq2).
// This step is necessary because the order of frequencies doesn't matter, only their values.
// Comparing Sorted Frequencies:

// Iterate through the sorted frequency vectors and compare corresponding elements.
// If any corresponding elements are not equal, return false.
// Final Result:

// If all the checks pass, return true, indicating that the two words are "close" as per the problem definition.
// Complexity
// Time complexity:
// $$O(n)$$
// (Sorting on a constant Array (n=26) does not affect the time complexity of the algorithm)

// Space complexity:
// $$O(1)$$

class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        std::vector<int> freq1(26, 0);
        std::vector<int> freq2(26, 0);

        for (char ch : word1) {
            freq1[ch - 'a']++;
        }

        for (char ch : word2) {
            freq2[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        std::sort(freq1.begin(), freq1.end());
        std::sort(freq2.begin(), freq2.end());

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }
};
