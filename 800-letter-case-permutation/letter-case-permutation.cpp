class Solution {
    public:
    vector<string>ans;
    void permute(string curr,int i,string s)
    {
        if(i == s.length())
        {
            ans.push_back(curr);
            return;
        }
        if(isdigit(s[i]))
        {
            curr.push_back(s[i]);
            permute(curr,i+1,s);
        }
        else 
        {
            string c1 = curr;
            c1.push_back(tolower(s[i]));
            permute(c1,i+1,s);

            string c2 = curr;
            c2.push_back(toupper(s[i]));
            permute(c2,i+1,s);
        }
    }
    vector<string> letterCasePermutation(string s) 
    {
        permute("",0,s);
        return ans;
    }
};