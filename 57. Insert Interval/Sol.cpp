// Intuition
// To solve this problem, we can utilize the fact that the intervals are sorted and non-overlapping. We can iterate through the intervals and compare them with the new interval to determine the correct position for insertion. If there is an overlap, we merge the intervals.

// Approach
// Approach 1 :
// In this approach, we iterate through each interval in the given vector and compare it with the new interval. We handle three cases:

// If the current interval ends before the new interval starts, we continue iterating.
// If the current interval starts after the new interval ends, we insert the new interval at the current position.
// If there is an overlap between the current interval and the new interval, we merge them and update the new interval accordingly.
// Approach 2:
// In this approach, we also iterate through each interval, but instead of modifying the original vector, we maintain a separate vector to store the merged intervals. We handle the same three cases as in Approach 1. After iterating through all intervals, we append the remaining intervals from the original vector to the result vector.

// Complexity
// - Time complexity:

// Approach 1: O(n^2)
// Approach 2: O(n)
// - Space complexity:
// Both approaches: O(n)
// Code
Approach 1

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        
        while(i < intervals.size()) {
            if(intervals[i][1] < newInterval[0])
                i++;
            else if (intervals[i][0] > newInterval[1]){
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            } else {
                //Overlap : merge them
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                intervals.erase(intervals.begin()+i);
            }
        }
        
        intervals.push_back(newInterval);
        return intervals;
    }
};
Approach 2

// Approach 2
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> result;
        
        while(i < intervals.size()) {
            if(intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                break;
            } else {
                //Overlap : merge them
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        
        result.push_back(newInterval);
        while(i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};
// Dry Run :

// intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
// newInterval = [4,8]
// Approach 1 :
// Initialize i = 0.
// Check intervals[0] = [1,2], intervals[0][1] < newInterval[0], so continue.
// Increment i, i = 1.
// Check intervals[1] = [3,5], intervals[1][0] <= newInterval[1], so merge them (newInterval = [3,8]).
// Increment i, i = 2.
// Check intervals[2] = [6,7], intervals[2][0] > newInterval[1], so push newInterval to intervals and break.
// Insert newInterval at index 2, resulting in intervals = [[1,2],[3,8],[6,7],[8,10],[12,16]].
// The approach continues until all intervals are processed.

// Approach 2:
// Initialize i = 0 and an empty result vector.
// Check intervals[0] = [1,2], intervals[0][1] < newInterval[0], so push intervals[0] to result.
// Increment i, i = 1.
// Check intervals[1] = [3,5], intervals[1][0] <= newInterval[1], so merge them (newInterval = [3,8]).
// Increment i, i = 2.
// Check intervals[2] = [6,7], intervals[2][0] > newInterval[1], so push newInterval to result and break.
// Append remaining intervals to result.
// Return [[1,2],[3,8],[6,7],[8,10],[12,16]].
// Both approaches will give the same correct output [[1,2],[3,8],[6,7],[8,10],[12,16]] for the given input. However, Approach 1 might take more time due to the repeated insertions and deletions in the original vector, while Approach 2 maintains a separate result vector, leading to better performance.

// Note :
// Key Point to Convert Brute Force to Optimal:
// In the brute force approach, we iterated through each interval and checked for overlaps with the new interval. This resulted in an O(n^2) time complexity as for each interval, we potentially traversed the entire list of intervals.

// In the optimal approach, we utilized the fact that the intervals are sorted. We iterated through the list once and efficiently merged intervals that overlap with the new interval. This approach results in linear time complexity (O(n)). Additionally, we maintained a separate result vector to store the merged intervals, eliminating the need for repeated insertions and deletions in the original vector.
