// Intuition 🧠
// The goal is to maximize the total importance of the roads by assigning importance values to cities. 
// The importance of a road is the sum of the importance values of the two cities it connects. 
// To achieve the maximum total importance, cities with more connections (higher degrees) should be assigned higher importance values.

// Approach 🚀
// Count Connections: Traverse the list of roads and count the number of connections (roads) each city has. 
// This can be stored in an array where each index represents a city, and the value at that index represents the number of roads connected to that city.

// Sort Connections: Sort the array of connection counts in ascending order. This allows us to assign the smallest 
// importance values to the cities with the fewest connections and the largest importance values to the cities with the most connections.
// Assign Importance: Initialize a variable cost to 1, representing the lowest importance value. Iterate through the sorted 
// connections array, multiplying each value by the current cost, and add the result to the total importance. Increment cost after each multiplication.
// Return Result: The total importance calculated in the previous step is the maximum importance of the roads.
// Complexity 📊
// Time complexity: (O(n*log n + m)), where (n) is the number of cities and (m) is the number of roads. 
// Sorting the connections array takes (O(n*log n)), and counting the connections takes (O(m)).
// Space complexity: (O(n)), where (n) is the number of cities. This is due to the space needed to store the connections array.

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long res = 0, cost = 1;
        vector<int> conn(n, 0);
        for (auto road : roads) {
            conn[road[0]]++;
            conn[road[1]]++;
        }
        sort(conn.begin(), conn.end());
        for (auto con : conn) res += con * (cost++);
        return res;
    }
};

// The image shows an example of a graph with 5 cities and several roads connecting them. Here’s the detailed step-by-step approach based on the image:

// Count Connections:

// City 0 has 3 connections: to cities 1, 2, and 3.
// City 1 has 3 connections: to cities 0, 2, and 3.
// City 2 has 4 connections: to cities 0, 1, 3, and 4.
// City 3 has 3 connections: to cities 0, 1, and 2.
// City 4 has 1 connection: to city 2.
// Sort Connections:

// The connections array before sorting: ([3, 3, 4, 3, 1]).
// The connections array after sorting: ([1, 3, 3, 3, 4]).
// Assign Importance:

// Assign importance values starting from 1.
// City with 1 connection gets importance 1.
// Cities with 3 connections get importance 2, 3, and 4.
// City with 4 connections gets importance 5.
// Importance values assigned: ([1, 2, 3, 4, 5]).
// Calculate Total Importance:

// Multiply the sorted connections by their assigned importance values and sum them up.
// Total importance = (1 \times 1 + 3 \times 2 + 3 \times 3 + 3 \times 4 + 4 \times 5 = 1 + 6 + 9 + 12 + 20 = 48).
