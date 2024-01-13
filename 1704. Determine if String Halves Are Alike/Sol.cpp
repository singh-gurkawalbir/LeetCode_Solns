// Approaches
// (Also explained in the code)

// Vowel Set:

// Create an unordered set (vowels) containing all the vowel characters.
// Initialize Variables:

// Initialize vowelsCount to 0 to keep track of the difference in the count of vowels between the two halves.
// Find the midIndex of the string, which represents the index where the second half starts.
// Iterate Over Halves:

// Use a loop to iterate over the first half and the corresponding characters in the second half simultaneously.
// Check if each character in both halves is a vowel, updating vowelsCount accordingly.
// Check Equality:

// After the loop, check if vowelsCount is equal to 0. If so, the two halves have an equal number of vowels.
// Complexity
// Time complexity:
// $$O(n)$$

// Space complexity:
// $$O(1)$$

class Solution {
public:
    bool halvesAreAlike(std::string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int vowelsCount = 0;
        int midIndex = s.length() / 2;

        for (int i = 0; i < midIndex; i++) {
            char charA = s[i];
            char charB = s[midIndex + i];
            if (vowels.count(charA)) vowelsCount++;
            if (vowels.count(charB)) vowelsCount--;
        }

        return vowelsCount == 0;
    }
};
