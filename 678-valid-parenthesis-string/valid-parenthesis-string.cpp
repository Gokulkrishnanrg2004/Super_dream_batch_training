class Solution {
public:
    bool checkValidString(string s) 
    {
        int cmin = 0,cmax = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                cmax++;
                cmin++;
            }
            else if(s[i] == ')')
            {
                cmax--;
                cmin = max(cmin - 1,0);
            }
            else if(s[i] == '*')
            {
                cmax++;
                cmin = max(cmin - 1,0);
            }
            if(cmax < 0) return false;
        }
        return cmin == 0;
    }
};