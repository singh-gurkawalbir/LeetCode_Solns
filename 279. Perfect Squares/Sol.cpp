class Solution {
public:
    std::vector<int> memo;

    int solve(int n) {
        if(n == 0) return 0;
        if(n < 0) return INT_MAX;
        if(memo[n] != -1) return memo[n];
        int ans = INT_MAX;
        for(int i = 1; i * i <= n; i++) {
            ans = std::min(ans, 1 + solve(n - (i * i)));
        }
        return memo[n] = ans;
    }
    int numSquares(int n) {
        memo.resize(n + 1, -1);
        return solve(n);
    }
};

//Check this video to understand answer
//https://www.youtube.com/watch?v=hGYemyJ8ePc
