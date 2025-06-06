class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {
        long long zero1 = 0, zero2 = 0,sum1 = 0, sum2 = 0;
        for(int num : nums1)
        {
            if(num == 0)
                zero1++;
            sum1 += num;
        }    
        for(int num : nums2)
        {
            if(num == 0)
                zero2++;
            sum2 += num;
        }
        if(zero1 == 0 && zero2 == 0)
        {
            return sum1 == sum2 ? sum1 : -1;
        }
        else if(zero1 == 0 && zero2 != 0)
        {
            return sum2 + zero2 <= sum1 ? sum1 : -1;
        }
        else if(zero1 != 0 && zero2 == 0)
        {
            return sum1 + zero1 <= sum2 ? sum2 : -1;
        }
        return max(sum1 + zero1, sum2 + zero2);
    }
};