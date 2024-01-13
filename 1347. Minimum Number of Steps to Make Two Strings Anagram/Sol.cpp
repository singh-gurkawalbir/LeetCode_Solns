// Intuition
// The idea is to compare the character counts in both strings to determine the number of steps required to make them anagrams. We can achieve this by counting the occurrences of each character in both strings and then calculating the absolute differences in counts.
// Approach
// 1. Initialize two arrays count_s and count_t of size 26 to represent the count of each character in the alphabet for both strings s and t.
// 2. Iterate through each character in string s and increment the corresponding count in count_s.
// 3. Iterate through each character in string t and increment the corresponding count in count_t.
// 4. Calculate the absolute differences in counts for each character and sum them up to get the total number of steps.
// 5. Return the total number of steps divided by 2 since each step involves changing one character, and we count each change twice.
// Complexity
// Time complexity:
// $$O(n)$$, where n is the length of the input strings s and t. We iterate through each character in both strings once.
// Space complexity:
// $$O(1)$$, since the size of the arrays count_s and count_t is constant (26 characters).

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        std::vector<int> count_s(26, 0);
        std::vector<int> count_t(26, 0);

        for (char ch : s) {
            count_s[ch - 'a']++;
        }

        for (char ch : t) {
            count_t[ch - 'a']++;
        }

        int steps = 0;
        for (int i = 0; i < 26; i++) {
            steps += std::abs(count_s[i] - count_t[i]);
        }

        return steps / 2;  
    }
};
