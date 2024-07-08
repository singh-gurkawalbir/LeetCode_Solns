int solve(int n, int k, vector<int>& arr, int s) {
    if (arr.size() == 1) {
        return arr[0];
    }
    s = (s + k - 1) % n;
    arr.erase(arr.begin() + s);
    int ans = solve(n - 1, k, arr, s);
    return ans;
}
// Parameters:

// n: Current size of the array (number of people remaining).
// k: The step count for elimination.
// arr: The array representing the circle of people.
// s: The current starting index for counting.
// Base Case:

// If only one person remains (arr.size() == 1), return that person (arr[0]).
// Recursive Case:

// Calculate the index of the next person to be eliminated: s = (s + k - 1) % n.
// Remove the person at index s from the array: arr.erase(arr.begin() + s).
// Recursively call solve with the updated parameters:
// Decrease the number of people n by 1.
// The starting index s is updated.
// Return the result of the recursive call.

int findTheWinner(int n, int k) {
    vector<int> arr;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        arr.push_back(i + 1);
    }
    int ans = solve(n, k, arr, s);
    return ans;
}
// Initialization:

// Create a vector arr to represent the circle of people.
// Initialize the starting index s to 0.
// Fill the vector with people numbered from 1 to n.
// Solving:

// Call the recursive solve method with the initial parameters: n, k, arr, and s.
// Return the result (ans) from the solve method.
// How It Works with an Example
// Let's take n = 7 and k = 4 to see how it works:

// Initialization:

// arr = [1, 2, 3, 4, 5, 6, 7]
// s = 0
// First Recursive Call:

// s = (0 + 4 - 1) % 7 = 3
// Remove person at index 3 (4): arr = [1, 2, 3, 5, 6, 7]
// Call solve(6, 4, arr, 3)
// Second Recursive Call:

// s = (3 + 4 - 1) % 6 = 0
// Remove person at index 0 (1): arr = [2, 3, 5, 6, 7]
// Call solve(5, 4, arr, 0)
// Third Recursive Call:

// s = (0 + 4 - 1) % 5 = 3
// Remove person at index 3 (6): arr = [2, 3, 5, 7]
// Call solve(4, 4, arr, 3)
// Fourth Recursive Call:

// s = (3 + 4 - 1) % 4 = 2
// Remove person at index 2 (5): arr = [2, 3, 7]
// Call solve(3, 4, arr, 2)
// Fifth Recursive Call:

// s = (2 + 4 - 1) % 3 = 2
// Remove person at index 2 (7): arr = [2, 3]
// Call solve(2, 4, arr, 2)
// Sixth Recursive Call:

// s = (2 + 4 - 1) % 2 = 1
// Remove person at index 1 (3): arr = [2]
// Call solve(1, 4, arr, 1)
// Base Case:

// Only one person remains: arr = [2]
// Return 2
// The winner is 2, which matches our earlier explanation.

