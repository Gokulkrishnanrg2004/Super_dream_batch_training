class Solution {
    public:
    bool isSymmetric(string num, int n)
    {
        if(n%2 == 0)
        {
            int mid = n/2;
            int sum1 = 0, sum2 = 0;
            for(int i=0;i<mid;i++)
            {
                sum1 += num[i] - '0';
            }
            for(int i=n-1;i>=mid;i--)
            {
                sum2 += num[i] - '0';
            }
            return (sum1 == sum2) ? true : false;
        }
        return false;
    }
    int countSymmetricIntegers(int low, int high) 
    {
        int count = 0;
        for(int i = low;i<=high;i++)
        {
            string num = to_string(i);
            if(isSymmetric(num,num.size()))
            {
                count++;
            }
        }
        return count;
    }
};