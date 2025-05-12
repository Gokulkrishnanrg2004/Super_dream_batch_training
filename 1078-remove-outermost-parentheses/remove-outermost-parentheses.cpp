class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        string result = "";
        int n = s.length();
        int count = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                if(count == 0)
                {
                    count++;
                }
                else 
                {
                    result += s[i];
                    count++;
                }
            }
            else if(s[i] == ')')
            {
                if(count == 1)
                {
                    count--;
                }
                else 
                {
                    result += s[i];
                    count--;
                }
            }
        }
        return result;
    }
};