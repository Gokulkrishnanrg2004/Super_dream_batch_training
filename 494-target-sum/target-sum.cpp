class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum = 0;
        for(int num : nums)
        {
            sum += num;
        }    
        if((sum+target)%2!=0 || sum<abs(target))
            return 0;
        int subsetsum = (sum+target)/2;
        vector<int>dp(subsetsum+1);
        dp[0] = 1;
        for(int num : nums)
        {
            for(int i = subsetsum;i>=num;i--)
            {
                dp[i]+=dp[i-num];
            }
        }
        return dp[subsetsum];
    }
};