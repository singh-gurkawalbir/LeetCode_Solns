/*
Step-by-Step Breakdown
1. Traverse the Linked List:
Purpose: Identify critical points, which are either local minima or local maxima.
Details: Iterate through the linked list while maintaining a pointer for the previous node and the current node. This allows comparison between the previous, current, and next node values to determine if the current node is a critical point.

2. Record Positions of Critical Points:
Purpose: Store the positions (indices) of the critical points for distance calculations.
Details: As you traverse the list, if a node is determined to be a critical point, store its position in an array or list.

3. Calculate Distance
Purpose: Determine the minimum and maximum distances between the identified critical points.
Details:
If fewer than two critical points are identified, return [-1, -1] immediately.
Otherwise, compute the minimum distance between consecutive critical points and the maximum distance between the first and last critical points in the list.

4. Return the Results:
Purpose: Provide the final result in the required format.
Details: Return an array containing the minimum and maximum distances.
*/
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int position = 0;
        
        while (curr != nullptr && curr->next != nullptr) {
            if (prev != nullptr && curr->next != nullptr) {
                if ((curr->val > prev->val && curr->val > curr->next->val) || 
                    (curr->val < prev->val && curr->val < curr->next->val)) {
                    criticalPoints.push_back(position);
                }
            }
            prev = curr;
            curr = curr->next;
            position++;
        }
        
        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }
        
        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();
        
        for (int i = 1; i < criticalPoints.size(); i++) {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }
        
        return {minDistance, maxDistance};
    }
};
