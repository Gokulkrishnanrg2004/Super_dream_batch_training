class Solution 
{
public:
    bool canSegment(int ind, string &s, unordered_set<string> &dict, vector<int> &dp)
    {
        if (ind == s.length())
            return true;
        if (dp[ind] != -1)
            return dp[ind];

        for (int i = ind + 1; i <= s.length(); i++)
        {
            string prefix = s.substr(ind, i - ind);
            if (dict.count(prefix) && canSegment(i, s, dict, dp))
            {
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return canSegment(0, s, dict, dp);
    }
};
