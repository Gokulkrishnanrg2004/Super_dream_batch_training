class Solution {
    public:
    int getval(int n,int k)
    {
        int res = 1;
        if(k > n - k)
        {
            k = n - k;
        }
        for(int i=0;i<k;i++)
        {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>>mat;
        for(int row=0;row<n;row++)
        {
            vector<int>arr;
            for(int i=0;i<=row;i++)
            {
                arr.push_back(getval(row,i));
            }
            mat.push_back(arr);
        }
        return mat;
    }
};