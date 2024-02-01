class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> v;                                              // Make 2d array to store the 1d array of size 3   
        sort(nums.begin(), nums.end());                                 // Sort the given array                
        for (int i = 0; i + 2 < nums.size(); ++i) {                    // Iterate through the array
            if (i % 3 == 0) {                                         // Check index is multiple of 3 because we store the element in array at index =0,3,6                  
                if (nums[i + 2] - nums[i] <= k) {                    // Difference between 3rd and 2nd elements in the triplet is <= k             
                    v.push_back({nums[i], nums[i + 1], nums[i + 2]});           // If true, push 3 element together form i to i+2
                } else {
                    return {};                                          // If false, return an empty vector- no array is possible
                }
            }
        }
        return v;      // Return the array
    }
};

// The idea involves dividing an array into groups of three such that the absolute difference between the maximum and minimum element in each group is less than or equal to k.
// -- Sorting the array helps us to form groups with consecutive elements.

// Sort the given array nums in ascending order.

// Iterate through the sorted array in steps of 3.

// For each group of three consecutive elements, check if the absolute difference between the maximum and minimum element is less than or equal to k.

// If the condition is satisfied, add the group to the $$result$$.

// If any group fails the condition, return an empty array since it's not possible to form valid groups.

// Complexity
// Time complexity: O(N*logN)
// Space complexity: O(1)


