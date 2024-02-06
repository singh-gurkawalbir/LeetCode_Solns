class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;                        // Vector to store the final result 
        unordered_map<string, vector<string>> mp;         // Create an unordered_map to map sorted strings
        for(int i = 0; i < strs.size(); i++) {           // Iterate through each string
            string s = strs[i];                         // Store the original string
            sort(strs[i].begin(), strs[i].end());      // Sort the characters in the string to identify anagrams
            mp[strs[i]].push_back(s);                 // Map the sorted string to its original string in the unordered_map
        }
        for(auto i : mp)                          // Iterate through the unordered_map and push the grouped anagrams to the result vector
            ans.push_back(i.second);
        
        return ans;      // Return the final result
    }
};

// Explanation
// 1. Initialization:

//  Create an empty vector of vectors ans to store the grouped anagrams.
//  Create an unordered_map mp to map sorted strings to their original strings.
// 2. Iteration: Iterate through each string in the input vector strs.

//    Store the original string in variable s.  Example `eat` store in s
//    Sort the characters in the string to identify anagrams.  sort strs-  'aet'
//    Map the sorted string to its original string in the unordered_map mp. Store 'mp[aet].push_back(eat)'
// 3. Return result:

//      Iterate through the unordered_map mp and push the grouped anagrams to the result vector ans.
//      Return the final result vector ans containing the grouped anagrams.
// Time Complexity - O(N * K * log(K))
// Space Complexity-O(N * K)

// You can refer to the DRY RUN for better understanding.
// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// For i=0: "eat"

// Save the original string "eat" in variable s.
// Sort the string "eat" to obtain "aet".
// Push "eat" into the list associated with key "aet".
// For i=1 :"tea"

// Save the original string "tea" in variable s.
// Sort the string "tea" to obtain "aet".
// Push "tea" into the list associated with key "aet".
// For i=2: "tan"

// Save the original string "tan" in variable s.
// Sort the string "tan" to obtain "ant".
// Push "tan" into the list associated with key "ant".
// For i=3: "ate"

// Save the original string "ate" in variable s.
// Sort the string "ate" to obtain "aet".
// Push "ate" into the list associated with key "aet".
// For i=4: "nat"

// Save the original string "nat" in variable s.
// Sort the string "nat" to obtain "ant".
// Push "nat" into the list associated with key "ant".
// For i=5: "bat"

// Save the original string "bat" in variable s.
// Sort the string "bat" to obtain "abt".
// Push "bat" into the list associated with key "abt"
