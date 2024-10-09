class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        // Sort the points by the end of each balloon's range
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;  // Start with one arrow
        int end = points[0][1];  // Set the end of the first balloon

        // Iterate over the sorted balloons
        for (int i = 1; i < points.size(); ++i) {
            // If the current balloon starts after the previous one ends, we need a new arrow
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];  // Update the end to the current balloon's end
            }
        }

        return arrows;
    }
};

// Let's perform a dry run of the provided C++ code for the findMinArrowShots function. This function is designed to determine the minimum number of arrows required to burst a collection of balloons represented by their starting and ending coordinates.
// Input:
// points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}}

// Step-by-Step Dry Run:

//     Initial Setup:
//         Given points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}}.
//         Check if points is empty:
//             It is not empty, so we proceed.

//     Sorting the Points:
//         The function sorts the points based on the end coordinate of each balloon:
//         Sorted points becomes:
//         points = {{1, 6}, {2, 8}, {7, 12}, {10, 16}}

//     Initial Arrow Count:
//         Initialize arrows = 1 (we start with one arrow).
//         Initialize end = points[0][1] = 6 (the end of the first balloon).

//     Iteration Over Balloons:
//         Start iterating from the second balloon (index 1).

// Iteration 1 (i = 1):

//     Current balloon: {2, 8}
//     Check if points[1][0] > end:
//         points[1][0] = 2, end = 6.
//         Since 2 <= 6, there is overlap between the current balloon and the previous one.
//         No new arrow is needed.
//         arrows remains 1.

// Iteration 2 (i = 2):

//     Current balloon: {7, 12}
//     Check if points[2][0] > end:
//         points[2][0] = 7, end = 6.
//         Since 7 > 6, there is no overlap.
//         We need a new arrow, so we increment arrows:
//             arrows++ → arrows = 2.
//         Update end = points[2][1] = 12 (the end of the current balloon).

// Iteration 3 (i = 3):

//     Current balloon: {10, 16}
//     Check if points[3][0] > end:
//         points[3][0] = 10, end = 12.
//         Since 10 <= 12, there is overlap.
//         No new arrow is needed.
//         arrows remains 2.

// Final Result:

//     The loop ends as all balloons have been processed.
//     The minimum number of arrows required is arrows = 2.

// Final Output:
// return 2;

// Summary:

//     Arrows used:
//         One arrow bursts balloons {1, 6} and {2, 8}.
//         Another arrow bursts balloon {7, 12}.
//         Balloon {10, 16} is also burst by the second arrow, hence no additional arrow is needed.
