
// 1. The `findWinners` method is called with a vector of vectors of integers as input.
// 2. A map called `lost` is initialized to keep track of the number of losses for each player.
// 3. The method iterates over each match in the input vector and updates the loss count for each player:
//    - If the player is not in the `lost` map, it initializes their loss count to 0.
//    - It then increments the loss count for the opponent of the player.
// 4. Two vectors, `zero` and `ones`, are created to store the players with 0 losses and 1 loss respectively.
// 5. The method iterates over the `lost` map and populates the `zero` and `ones` vectors based on the loss count:
//    - If a player has 0 losses, they are added to the `zero` vector.
//    - If a player has 1 loss, they are added to the `ones` vector.
// 6. Finally, the method returns a vector containing `zero` and `ones`, which represent the players with 0 losses and 1 loss respectively.

// This dry run outlines the step-by-step execution of the `findWinners` method based on the provided code snippet.

// Intuition
// The goal is to identify players who have not lost any matches and those who have lost exactly one match based on the provided match results. We can achieve this by keeping track of each player's loss count using a map.

// Approach
// Create a map named lost to store the loss count for each player.
// Iterate through the given matches:
// If the winner is not in the lost map, initialize their loss count to 0.
// Increment the loss count for the loser.
// Create two vectors, zero and ones, to store players with 0 and 1 loss, respectively.
// Iterate through the lost map using structured bindings:
// If the loss count is 0, add the player to the zero vector.
// If the loss count is 1, add the player to the ones vector.
// Return a 2D vector containing the zero and ones vectors.
// Complexity
// Time complexity: O(n), where n is the number of matches. The algorithm iterates through the matches once.
// Space complexity: O(m), where m is the number of unique players. The space required is proportional to the number of players in the map and the vectors.


class Solution 
{
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        map<int,int> lost;
        for (auto m : matches)
        {
            lost[m[0]] += 0;
            lost[m[1]]++;
        }
        
        vector<int> zero, ones;
        for (auto[k,l] : lost)
        {
            if (l == 0) zero.push_back(k);
            if (l == 1) ones.push_back(k);
        }
        
        return {zero,ones};
    }
};
