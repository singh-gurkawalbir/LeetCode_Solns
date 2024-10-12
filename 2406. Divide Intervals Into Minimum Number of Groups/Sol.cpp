class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start_times, end_times;

        // Extract start and end times
        for (const auto& interval : intervals) {
            start_times.push_back(interval[0]);
            end_times.push_back(interval[1]);
        }

        // Sort start and end times
        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int end_ptr = 0, group_count = 0;

        // Traverse through the start times
        for (int start : start_times) {
            if (start > end_times[end_ptr]) {
                end_ptr++;
            } else {
                group_count++;
            }
        }

        return group_count;
    }
};

// Intuition
// We need to group intervals so that no intervals in the same group overlap. By sorting start and end times, we can track how many intervals overlap at any point. If a new interval starts after an earlier one ends, we can reuse that group. Otherwise, we need a new group.
// Approach

// This solution implements an algorithm to find the minimum number of non-overlapping groups that can be formed from a set of intervals. Here's a step-by-step breakdown of the solution:

// Problem Statement:
// Given a list of intervals, each interval is represented as a pair [start, end], where start is the start time and end is the end time of the interval. The goal is to group these intervals such that no two intervals within the same group overlap, and return the minimum number of such groups required.

// Explanation of the Code:
// Input: The input is a vector of intervals (intervals), where each interval is represented as a vector of two integers, [start, end].

// Start and End Times Extraction:

// The algorithm first extracts all the start times and end times from the intervals and stores them into separate vectors start_times and end_times, respectively.
// cpp
// Copy code
// for (const auto& interval : intervals) {
//     start_times.push_back(interval[0]);
//     end_times.push_back(interval[1]);
// }
// Sorting:

// Both the start_times and end_times vectors are then sorted. Sorting helps in efficiently determining when a new group needs to be created by comparing the start and end times.
// cpp
// Copy code
// sort(start_times.begin(), start_times.end());
// sort(end_times.begin(), end_times.end());
// Logic for Grouping Intervals:

// The idea is to traverse the sorted start_times and check when a new group needs to be created. If the start of the current interval is greater than the end of an interval from a previous group (pointed by end_ptr), then that interval can fit into the existing group. In this case, we increment end_ptr.
// If the start of the current interval does not fit into the current group (i.e., it starts before the current end_ptr), a new group is needed, and we increment the group_count.
// cpp
// Copy code
// int end_ptr = 0, group_count = 0;
// for (int start : start_times) {
//     if (start > end_times[end_ptr]) {
//         end_ptr++;
//     } else {
//         group_count++;
//     }
// }
// Return Value:

// The group_count will hold the minimum number of groups required to ensure no intervals overlap within any group, and this value is returned as the final result.
// cpp
// Copy code
// return group_count;
// Dry Run Example:
// Consider the following input intervals:

// lua
// Copy code
// intervals = [[1, 4], [2, 3], [3, 5], [7, 8]]
// Extract start_times = [1, 2, 3, 7] and end_times = [4, 3, 5, 8]
// After sorting, we get:
// start_times = [1, 2, 3, 7]
// end_times = [3, 4, 5, 8]
// Now let's walk through the loop:

// First interval starts at 1, and the first end time is 3.

// start = 1 <= 3, so we need a new group.
// group_count = 1
// Second interval starts at 2, and the current end time is still 3.

// start = 2 <= 3, so we need another group.
// group_count = 2
// Third interval starts at 3, and the current end time is 3.

// start = 3 <= 3, so we need another group.
// group_count = 3
// Fourth interval starts at 7, and the next available end time is 5.

// start = 7 > 5, so we can reuse a group, and end_ptr++.
// Final group_count = 3, which is the result.

// Time Complexity:
// Extracting the start and end times takes O(n), where n is the number of intervals.
// Sorting the start_times and end_times takes 𝑂(𝑛log𝑛).
// The traversal of the start_times takes 
// O(n). Thus, the overall time complexity is O(nlogn).
