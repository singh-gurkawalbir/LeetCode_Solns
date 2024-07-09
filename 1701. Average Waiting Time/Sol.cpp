// Code Explanation
// Initialization:

// available_at is initialized to 0. This keeps track of the next available time when the chef can start preparing the next customer's order.
// total_wait is initialized to 0. This accumulates the total waiting time for all customers.
// Loop through each customer:

// For each customer, the code retrieves the arrival time and the preparation time (t).
// available_at = max(available_at, arrival) + t updates the next available time. It ensures that the chef starts preparing the order either when the customer arrives or when the chef becomes available, whichever is later.
// total_wait += available_at - arrival calculates the waiting time for the current customer and adds it to total_wait. The waiting time is the difference between the time when the order is completed (available_at) and the customer's arrival time.
// Calculate and return the average waiting time:

// The average waiting time is calculated by dividing the total_wait by the number of customers.
// Example
// Let's go through an example to understand this better:

// Input:

// cpp
// Copy code
// vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};
// Step-by-Step Execution:

// Customer 1:

// arrival = 1, t = 2
// available_at = max(0, 1) + 2 = 3
// total_wait = 3 - 1 = 2
// Customer 2:

// arrival = 2, t = 5
// available_at = max(3, 2) + 5 = 8
// total_wait = 2 (previous) + 8 - 2 = 8
// Customer 3:

// arrival = 4, t = 3
// available_at = max(8, 4) + 3 = 11
// total_wait = 8 (previous) + 11 - 4 = 15
// Average Waiting Time:

// total_wait = 15
// number of customers = 3
// average waiting time = 15 / 3 = 5.0
Final Code
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int available_at = 0;
        double total_wait = 0;
        for (auto& customer : customers) {
            int arrival = customer[0], t = customer[1];
            available_at = max(available_at, arrival) + t;
            total_wait += available_at - arrival;
        }
        return (double) total_wait / customers.size();
    }
};
// In this example, the average waiting time is 5.0, which is returned by the function.
