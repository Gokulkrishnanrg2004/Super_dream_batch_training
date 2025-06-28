class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if ((target + totalSum) % 2 != 0 || totalSum < abs(target))
            return 0;

        int subsetSum = (target + totalSum) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(subsetSum + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 0; j <= subsetSum; j++) 
            {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];  // include or exclude
                else
                    dp[i][j] = dp[i - 1][j];  // can't include
            }
        }

        return dp[n][subsetSum];
    }
};