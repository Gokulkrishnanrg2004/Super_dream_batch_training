class Solution {
public:
    int maxDepth(string s) 
    {
        int n = s.length();
        int count = 0;
        int maxdepth = INT_MIN;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                count++;
            }
            else if(s[i] == ')')
            {
                count--;
            }
            maxdepth = max(maxdepth,count);
        }
        return maxdepth;
    }
};