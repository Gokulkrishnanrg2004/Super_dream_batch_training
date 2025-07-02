class Solution {
public:
    int kthFactor(int n, int k) 
    {
        vector<int> small,large;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i == 0)
            {
                small.push_back(i);
                if(i != n/i)
                {
                    large.push_back(n/i);
                }
            }
        }    
        for(int i=large.size()-1;i>=0;i--)
        {
            small.push_back(large[i]);
        }
        return (k<=small.size()) ? small[k-1] : -1;
    }
};