class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j * j <= i; ++j) 
        { // Check all square numbers <= i
            if (!dp[i - j * j]) { // If removing j*j leaves the opponent in a losing state
                dp[i] = true;     // Alice can win
                break;
            }
        }
    }
    return dp[n];
    }
};