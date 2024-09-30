class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        // if(num==1)
        // {
        //     return true;
        // }   
        // for(int i=2;i<=num;i++)
        // {
        //     if((long long)i*i>num)
        //     {
        //         return false;
        //     }
        //     if((long long)i*i==num)
        //     {
        //         return true;
        //     }
        // }
        // return false;
        long long low = 1;
        long long high = num;
        while(low<=high)
        {
            long long mid = (low+high)/2;
            if((mid*mid)==num)
            {
                return true;
            }
            if((mid*mid) < num)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};