// Approach
// 1. Pairing and Sorting:

// Create pairs of (start time, job index) to associate start times with their corresponding jobs.
// Sort the pairs based on start times to ensure processing in ascending order.
// 2. Dynamic Programming Table:

// Create a DP table dp of size n+1, where dp[i] stores the maximum profit obtainable considering only jobs starting from index i onwards.
// 3. Backward Iteration:

// Iterate through the sorted pairs in reverse order (from last to first):
// For each pair (start time, job index):
// Calculate the potential profit by taking the current job's profit p[job_index] and adding the maximum profit from compatible jobs that start after its end time.
// Use binary search (lower_bound) to efficiently find the index of the earliest compatible job.
// Update dp[i] with the maximum of either including the current job or not.
// 4. Optimal Solution:

// The final value dp[0] represents the maximum profit achievable by scheduling a compatible set of jobs.
// Time Complexity:

// O(N * log N)
// Sorting the pairs takes O(N * log N) time.
// The backward iteration takes N steps.
// Each binary search within the loop takes O(log N) time on average.
// Space Complexity:

// O(N)
// The st vector, dp vector, and additional variables use space proportional to the number of jobs N.

class Solution {
public:

    int find(int i, vector<vector<int>>&job, vector<int>&startTime, int n,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        
        int index = lower_bound(startTime.begin(),startTime.end(),job[i][1])-startTime.begin();
        int pick = job[i][2] + find(index,job,startTime,n,dp);
        int notpick = find(i+1,job,startTime,n,dp);
        return dp[i] = max(pick,notpick);

    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<vector<int>>job;
        vector<int>dp(n,-1);
        for(int i =0;i<n;i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        sort(startTime.begin(),startTime.end());
        return find(0,job,startTime,n,dp);
        }
};
