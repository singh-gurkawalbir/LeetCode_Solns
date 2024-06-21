// Initialization:
// Start by computing sum of already satisfied customers (gr[i] == 0) and initial maxLoss for the first min customers.

// Sliding Window:
// Slide through the array from min to n (where n is the length of the arrays). Adjust maxLoss by subtracting the effect of the element going out of the window (gr[i] == 1 turns into gr[j] == 1) and adding the effect of the new element coming into the window (gr[j] == 1 turns into gr[i] == 1).

// Maximize Satisfaction:
// Continuously update maxLoss to store the maximum possible gain from converting unhappy customers within any window of size min.

// Complexity
// Time complexity:
// The algorithm runs in O(n) time due to the single pass through the array for calculating sum and the sliding window of size min.

// Space complexity:
// O(1) additional space is used apart from the input arrays, making it very efficient in terms of space complexity

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), satisfied = 0;

        for (int i = 0; i < n; i++) 
            if (!grumpy[i]) satisfied += customers[i];

        int maxGain = 0, currentGain = 0;
        for (int i = 0; i < minutes; i++) 
            if (grumpy[i]) currentGain += customers[i];
        maxGain = currentGain;

        for (int i = minutes; i < n; i++) 
        {
            if (grumpy[i]) currentGain += customers[i];
            if (grumpy[i - minutes]) currentGain -= customers[i - minutes];
            maxGain = max(maxGain, currentGain);
        }

        return satisfied + maxGain;
    }
};

