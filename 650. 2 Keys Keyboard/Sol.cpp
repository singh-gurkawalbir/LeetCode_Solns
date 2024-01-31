class Solution {
    public:
    int minSteps(int n) {
        if(n==1)return 0;
        if(n==2)return 2;
        
        vector<int>dp(n+1);
        
        dp[1] = 0;
        dp[2] = 2;
        
        for(int i =3;i<=n;i++){
            dp[i] = i;
            
            int j = i/2;
            while(j>=1){
                if(i%j==0){
                    dp[i] = min(dp[i] , dp[j] +i/j);
                }
                j--;
            }
        }
        
        return dp[n];
    }
};

// Base Cases:
// If n is 1, it means we already have the "A" character, so the minimum steps are 0.
// If n is 2, it means we have "AA," and the minimum steps are 2 (copy "A" and then paste).

// if (n == 1) return 0;
// if (n == 2) return 2;
// Dynamic Programming Array:
// Create a dynamic programming array dp of size n+1 to store the minimum steps for each i.

// vector<int> dp(n + 1);
// dp[1] = 0;
// dp[2] = 2;
// Dynamic Programming Loop:
// Iterate from i = 3 to n.
// Initialize dp[i] to i because one way to get i "A" characters is to copy a smaller sequence of "A" characters and paste it repeatedly (this is the worst-case scenario).

// for (int i = 3; i <= n; i++) {
//     dp[i] = i;
// Inner While Loop:
// Initialize j to i/2.
// While j is greater than or equal to 1:
// Check if i is divisible by j (i.e., i % j == 0).
// If divisible, update dp[i] to the minimum of its current value and the sum of dp[j] and i/j. This is because if we have a shorter sequence of "A" characters (j), we can copy and paste it (i/j) times to get i "A" characters.

// int j = i / 2;
// while (j >= 1) {
//     if (i % j == 0) {
//         dp[i] = min(dp[i], dp[j] + i / j);
//     }
//     j--;
// }
// Return Result:
// The final result is stored in dp[n], which represents the minimum steps required to form n "A" characters.

// return dp[n];
// In summary, the dynamic programming approach involves iterating through all possible values of i and considering the minimum steps required to form i "A"
// characters based on the optimal solutions for smaller values of j. The solution is built up iteratively, and the final result is stored in dp[n].

