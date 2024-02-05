class Solution {
public:
    int firstUniqChar(string s) {
       unordered_map<char, int> mp;

        for (auto a : s) mp[a]++;
        for (int i = 0; i < s.size(); i++)if(mp[s[i]] == 1)return i;

        return -1;
    }
}; 

// Approaches
// (Also explained in the code)

// Initialize an unordered map (mp) to store character counts.
// Iterate through the string to update character counts in the map.
// Iterate through the string again, return the index of the first character with a count of 1.
// Complexity
// Time complexity:
// $$O(n)$$

// Space complexity:
// $$O(U)$$
// (U is the number of unique characters in the string.)
