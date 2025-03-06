class Solution {
    public:
    vector<vector<int>>memo;
    int lcsrec(string& s1,string& s2,int m,int n)
    {
        if(m == 0 || n == 0)
            return 0;

        if(memo[m][n] != -1) return memo[m][n];

        if(s1[m-1] == s2[n-1])
            return memo[m][n] = 1 + lcsrec(s1,s2,m-1,n-1);

        else 
            return memo[m][n] = max(lcsrec(s1,s2,m-1,n),lcsrec(s1,s2,m,n-1));
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size();
        int n = text2.size();
        memo.assign(m+1,vector<int>(n+1,-1));
        return lcsrec(text1,text2,m,n);    
    }
};