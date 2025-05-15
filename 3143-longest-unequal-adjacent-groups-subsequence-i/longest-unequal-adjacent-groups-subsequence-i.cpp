class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) 
    {
        vector<string>result;
        int n = words.size();
        result.push_back(words[0]);
        for(int i=1;i<n;i++) 
        {
            if(words[i]!=words[i-1] && groups[i]!=groups[i-1])
            {
                result.push_back(words[i]);
            }
        }   
        return result;
    }
};