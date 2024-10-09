class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); // Step 1
        int x=0; // Step 2
        for(int l=0, r=people.size()-1; l<=r; r--){ // Step 3
            x++; // Step 4
            if (people[l] <= limit - people[r]) // Step 5
                l++; // Step 6
        }
        return x; // Step 7
    }
};

// Detailed Explanation:
// Step 1: sort(people.begin(), people.end());

//     We sort the people array in non-decreasing order based on their weights.
//     This allows us to handle the lightest and heaviest people systematically when trying to fit them into a boat.

// Step 2: int x=0;

//     We initialize a variable x to count the number of boats required.

// Step 3: for(int l=0, r=people.size()-1; l<=r; r--)

//     Two pointers are used: l points to the lightest person (starting from the left) and r points to the heaviest person (starting from the right).
//     The loop runs while l (the lightest person) is less than or equal to r (the heaviest person).

// Step 4: x++

//     Every iteration of the loop means one boat is used, so we increment x for every boat that is required.

// Step 5: if (people[l] <= limit - people[r])

//     We check if the lightest person (people[l]) can fit in the boat with the heaviest person (people[r]).
//         If people[l] + people[r] <= limit, then both can share the boat.
//         If this condition holds true, it means we can include the lightest person (l) with the heaviest person (r) in the same boat.

// Step 6: l++

//     If the lightest person can fit in the boat with the heaviest person, we increment l to point to the next lightest person.
//     Regardless of whether people[l] fits or not, we always decrement r because we always send the heaviest person in a boat in each iteration.

// Step 7: return x;

//     Once all people are processed (i.e., l > r), we return the number of boats used, which is stored in x.

// Example Dry Run:
// Input:

// people = [3, 5, 3, 4], limit = 5

//     Step 1: Sort people: [3, 3, 4, 5]
//     Step 2: Initialize x = 0, l = 0 (pointing to 3), r = 3 (pointing to 5)

//     Iteration 1:
//         people[l] = 3, people[r] = 5
//         3 + 5 > 5 (they cannot fit together)
//         Use one boat for people[r] = 5, increment x = 1, decrement r = 2

//     Iteration 2:
//         people[l] = 3, people[r] = 4
//         3 + 4 <= 5 (they can fit together)
//         Use one boat for both 3 and 4, increment x = 2, increment l = 1, decrement r = 1

//     Iteration 3:
//         people[l] = 3, people[r] = 3
//         3 + 3 <= 5 (they can fit together)
//         Use one boat for both 3 and 3, increment x = 3, increment l = 2, decrement r = 0

//     Now l > r, so the loop ends.

// Output:

//     The minimum number of boats required is 3.

// Time Complexity:

//     Sorting the array takes O(nlog⁡n)O(nlogn), where nn is the number of people.
//     The two-pointer loop runs in O(n)O(n), as each person is processed at most once.
//     Overall time complexity: O(nlog⁡n)O(nlogn).

// Space Complexity:

//     Sorting is done in-place, so the algorithm uses O(1)O(1) extra space (ignoring input space).
