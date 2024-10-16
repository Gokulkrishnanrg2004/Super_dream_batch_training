class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(i+1);
        }
        int i = 0;
        while(ans.size()>1)
        {
            i = i + k - 1;
            if(i>=ans.size())
            {
                i = i % ans.size();
            }
            ans.erase(find(ans.begin(),ans.end(),ans[i]));
        }
        return ans[0];
    }
};