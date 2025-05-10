class Solution {
public:
    int mySqrt(int n) 
    {
        if (n == 0 || n == 1) return n;
    int low = 1,high = n;
    int ans = 0;
    while(low <= high)
    {
        int mid = low+(high-low)/2;
        long long val = (long long)mid*mid;
        
        if (val == n) 
        {
            return mid;
        }
        else if(val < n)
        {
            ans = mid;
            low = mid+1;
        }
        else 
        {
            high = mid-1;
        }
    }
    return ans;    
    }
};