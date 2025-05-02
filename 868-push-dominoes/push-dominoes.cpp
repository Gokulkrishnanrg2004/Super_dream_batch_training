class Solution 
{
    public:
    string pushDominoes(string dom)
    {
        int n = dom.size();
        vector<int>force(n,0);

        int f = 0;
        for(int i=0;i<n;i++)
        {
            if(dom[i]=='R')
                f = n;
            else if(dom[i] == 'L')
                f = 0;
            else 
                f = max(f-1, 0);
            force[i] += f;
        }

        f = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(dom[i]=='L')
                f = n;
            else if(dom[i] == 'R')
                f = 0;
            else 
                f = max(f-1, 0);
            force[i] -= f;
        }

        string res = "";
        for(int f : force)
        {
            if(f > 0)
                res += 'R';
            else if(f < 0)
                res += 'L';
            else 
                res += '.';
        }
        return res;
    }
};