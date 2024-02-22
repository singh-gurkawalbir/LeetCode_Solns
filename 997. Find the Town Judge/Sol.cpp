// Using single vector

// Initialization: A vector V is initialized to represent the net trust count for each person.

// Loop and Update Trust Count: Iterate through trust relationships, updating trust counts based on who trusts and is trusted.

// Find the Judge: Check if there exists a person with a net trust count of n - 1 (trusted by everyone else). Return their index as the judge.

// Return Result: Return the judge's index if found, otherwise return -1.

// Time Complexity: O(E + N) E is the number of trust relationships.
// Space Complexity: O(N)

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustcount(n + 1, 0); 

        // Count trust relationships
        for (const auto& relation : trust) {
            trustcount[relation[0]]--;  
            trustcount[relation[1]]++;  
        }
        for (int i = 1; i <= n; ++i) {       // Check if there is a person who is trusted by everyone else
            if (trustcount[i] == n - 1) {
                return i;
            }
        }
        return -1;    // If no such person found, return -1
    }
};
