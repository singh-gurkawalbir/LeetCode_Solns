// Intuition
// The intuition behind this solution is to simulate the process of sharing the secret through meetings. We start with the person who has the secret at time 0 (firstPerson) and iterate through the meetings, updating the set of people who know the secret at each time. We use a breadth-first search (BFS) approach to discover new people who can know the secret.

// Approach
// We initialize a vector can of size n to represent whether a person can know the secret. We set the initial knowledge for person 0 and the specified firstPerson to be true.

// We use a map mp to group meetings based on time.

// We iterate through the meetings in ascending order of time. For each meeting, we build an adjacency list graph representing the relationships between people in the meeting. We also maintain a set st of people who currently know the secret.

// We use a queue q to perform BFS starting from the people who currently know the secret. We iterate through the queue and update the set of people who know the secret.

// After processing all meetings, we collect the indices of people who know the secret in the ans vector.

// Complexity
// Time complexity:
// O(E + V), where E is the number of edges (relationships) and V is the number of vertices (people).

// Space complexity:
// O(E + V), where E is the number of edges and V is the number of vertices. The space is used for storing the adjacency list and sets during the BFS process.

#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> can(n);  // Vector to represent whether a person can know the secret
        can[0] = can[firstPerson] = true;  // Person 0 and the person specified by firstPerson initially know the secret

        map<int, vector<pair<int, int>>> mp;  // Map to store meetings grouped by time

        // Group meetings based on time
        for (auto& meeting : meetings) 
            mp[meeting[2]].emplace_back(meeting[0], meeting[1]); 

        // Iterate through meetings
        for (auto& [k, v] : mp) {
            unordered_map<int, vector<int>> graph;  // Adjacency list to represent the graph of people in the meeting
            unordered_set<int> st;  // Set to store people who currently know the secret

            // Build the graph and set based on the people in the meeting
            for (auto& [x, y] : v) {
                graph[x].push_back(y); 
                graph[y].push_back(x); 
                if (can[x]) st.insert(x); 
                if (can[y]) st.insert(y); 
            }

            queue<int> q; 

            // Initialize the queue with people who currently know the secret
            for (auto& x : st) q.push(x); 
            
            // Perform BFS to find additional people who can know the secret
            while (q.size()) {
                auto x = q.front(); q.pop(); 
                for (auto& y : graph[x]) 
                    if (!can[y]) {
                        can[y] = true; 
                        q.push(y); 
                    }
            }
        }
        
        vector<int> ans; 

        // Collect the indices of people who know the secret
        for (int i = 0; i < n; ++i) 
            if (can[i]) ans.push_back(i); 

        return ans;  // Return the final list of people who know the secret
    }
};
