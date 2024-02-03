class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        int n = a.size();
        std::vector<int> dp(n, 0);
        dp[0] = a[0];

        for (int i = 1; i < n; i++) {
            int max_val = 0;
            int max_sum = 0;

            for (int j = i; j >= std::max(0, i - k + 1); j--) {
                max_val = std::max(a[j], max_val);

                if (j > 0) {
                    max_sum = std::max(max_sum, (i - j + 1) * max_val + dp[j - 1]);
                } else if (j == 0) {
                    max_sum = std::max(max_sum, (i - j + 1) * max_val);
                }
            }

            dp[i] = max_sum;
        }

        return dp[n - 1];
    }
};

// Watch this  video to undeerstnad the logic and do a dry run:
// https://www.youtube.com/watch?v=DLokut6TyaM
