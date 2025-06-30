class Solution {
    public:
    bool isSubsetSum(int n, vector<int>& arr, int sum, vector<vector<int>>& memo) 
    {
        if (sum == 0) return true;
        if (n == 0) return false;
    
        if (memo[n - 1][sum] != -1) return memo[n - 1][sum];

        if (arr[n - 1] > sum)
            return memo[n - 1][sum] = isSubsetSum(n - 1, arr, sum, memo);

        return memo[n - 1][sum] = isSubsetSum(n - 1, arr, sum, memo) || isSubsetSum(n - 1, arr, sum - arr[n - 1], memo);
    }
    bool canPartition(vector<int>& arr) 
    {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = arr.size();
        vector<vector<int>> memo(n, vector<int>(target + 1, -1));

        return isSubsetSum(n, arr, target, memo);   
    }
};