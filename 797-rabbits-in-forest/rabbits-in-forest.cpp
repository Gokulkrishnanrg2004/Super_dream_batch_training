class Solution {
public:
    int numRabbits(vector<int>& ans) 
    {
        sort(ans.begin(),ans.end());
        int res = 0, count = 0;

        for(int i=0;i<ans.size();i++)
        {
            if(ans[i] == 0)
            {
                res++;
            }
            else if(i == 0 || ans[i] != ans[i-1] || count == 0)
            {
                res += ans[i] + 1;
                count = ans[i];
            }
            else 
            {
                count--;
            }
        }    
        return res;
    }
};