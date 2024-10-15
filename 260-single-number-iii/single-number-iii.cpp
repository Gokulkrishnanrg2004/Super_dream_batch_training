class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int n = nums.size();
        long xorr = nums[0];
        for(int i=1;i<n;i++)
        {
            xorr = xorr ^ nums[i];
        }    
        long right = (xorr&(-xorr)); 
        int b1=0,b2=0;
        for(int i=0;i<n;i++)
        {
            if((nums[i]&right)!=0)
            {
                b1 ^= nums[i];
            }
            else 
            {
                b2 ^= nums[i];
            }
        }
        return {b1,b2};
    }
};