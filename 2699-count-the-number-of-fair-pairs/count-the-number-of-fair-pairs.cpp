class Solution {
    public:
    long long countMost(vector<int>&nums, long long comp)
    {
        long long ans = 0;
        for(int i = 0, j = nums.size() - 1;i<j;i++)
        {
            while(i<j && nums[i]+nums[j] > comp) --j;
            ans += j - i;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        sort(nums.begin(),nums.end());
        return countMost(nums,upper) - countMost(nums,lower-1);
    }
};