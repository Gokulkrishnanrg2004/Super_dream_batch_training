class Solution 
{
    public int solve(int i,int amount,int[] coins,int[][] dp)
    {
        if(i == 0)
        {
            if(amount % coins[0] == 0)return amount/coins[0];
            return (int)1e9;
        }
        if(dp[i][amount] != -1)
            return dp[i][amount];

        int ntake = solve(i-1,amount,coins,dp);
        int take = (int)1e9;
        if(coins[i] <= amount)
        {
            take = 1 + solve(i,amount - coins[i],coins,dp);
        }
        return dp[i][amount] = Math.min(take,ntake);
    }
    public int coinChange(int[] coins, int amount) 
    {
        int n = coins.length;
        int[][] dp = new int[n][amount+1];
        for(int[] row : dp)
        {
            Arrays.fill(row,-1);
        }    
        int res = solve(n-1,amount,coins,dp);
        return (res >= 1e9) ? -1 : res; 
    }
}