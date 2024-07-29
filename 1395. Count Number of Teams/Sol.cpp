// Approach
// Initialize Counters: For each soldier at index i, initialize counters to count soldiers with ratings less than or greater than rating[i], both to the left and right of i.

// Count Soldiers:

// Traverse the array to count soldiers with ratings less than or greater than rating[i] to the right of i.
// Traverse the array to count soldiers with ratings less than or greater than rating[i] to the left of i.
// Calculate Valid Teams: For each soldier i, the number of valid teams can be calculated as:
// Teams with increasing order: right_less * left_more
// Teams with decreasing order: right_more * left_less
// Sum the Counts: Sum these counts for all soldiers to get the total number of valid teams.

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int total = 0;

        for ( int i = 0 ; i < rating.size() ; i ++ ){
            int right_less = 0 , right_more = 0 , left_less = 0 , left_more = 0;

            for ( int j = i + 1 ; j < rating.size() ; j ++ ){
                if ( rating[j] < rating[i] ) right_less++;
                else if ( rating[i] < rating[j] ) right_more++;
            }
            for ( int j = 0 ; j < i ; j ++ ){
                if ( rating[j] < rating[i] ) left_less++;
                else if ( rating[i] < rating[j] ) left_more ++;
            }

            total += right_less*left_more + right_more*left_less;
        }

        return total;
    }
};
