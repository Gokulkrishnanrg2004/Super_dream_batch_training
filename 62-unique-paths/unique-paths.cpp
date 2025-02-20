class Solution {
    public:
    vector<vector<int>>dp;
    int countPath(int i,int j,int n,int m)
    {
        if(i==n-1 && j==m-1) return 1;
        if(i>=n || j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = countPath(i+1,j,n,m) + countPath(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) 
    {
        dp.resize(m,vector<int>(n,-1));
        return countPath(0,0,m,n);    
    }
};