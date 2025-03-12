class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int pc,nc = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] < 0)
            {
                nc++;
            }
            else if(nums[i] > 0)
            {
                pc++;
            }
        }
        return max(pc,nc);
    }
};