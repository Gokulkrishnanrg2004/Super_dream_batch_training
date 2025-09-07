class Solution {
    public:
    bool isPalindrome(const string& s,int left,int right)
    {
        while(left < right)
        {
            if(s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }
    void backtrack(const string& s,int start,vector<string>&path,vector<vector<string>>&result)
    {
        if(start == s.size())
        {
            result.push_back(path);
            return;
        }
        for(int end = start+1;end<=s.size();end++)
        {
            if(isPalindrome(s,start,end-1))
            {
                path.push_back(s.substr(start,end - start));
                backtrack(s,end,path,result);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>result;
        vector<string>path;
        backtrack(s,0,path,result);
        return result;
    }
};