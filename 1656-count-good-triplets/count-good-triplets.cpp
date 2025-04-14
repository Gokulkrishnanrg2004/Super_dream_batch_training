class Solution {
    public:
    bool isValid(int i,int j,int k,int a,int b,int c)
    {
        if(abs(i-j)<=a && abs(j-k)<=b && abs(i-k)<=c)
        {
            return true;
        }
        return false;
    }
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) 
    {
        int n = arr.size();
        int count = 0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k = j+1;k<n;k++)
                {
                    if(isValid(arr[i],arr[j],arr[k],a,b,c))
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};