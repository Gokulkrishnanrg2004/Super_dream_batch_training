class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int count=0;
        int prod = 1;
        int l=0;
        for(int r=0;r<nums.size();r++)
        {
            prod = prod*nums[r];
            while(prod>=k && l<=r)
            {
                prod = prod/nums[l];
                l++;
            }
            count+=(r-l)+1;
        }    
        return count;
    }
};