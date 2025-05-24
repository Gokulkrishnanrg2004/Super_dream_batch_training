class Solution 
{
    public:
    int atmostk(vector<int>&nums,int k)
    {
        int left = 0,count = 0;
        int n = nums.size();

        unordered_map<int,int>freq;
        for(int right = 0;right<n;right++)
        {
            if(freq[nums[right]] == 0)
            {
                k--;
            }
            freq[nums[right]]++;
            while(k < 0)
            {
                freq[nums[left]]--;
                if(freq[nums[left]] == 0)
                {
                    k++;
                }
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int sum1 = atmostk(nums,k);
        int sum2 = atmostk(nums,k-1);
        return sum1 - sum2;
    }
};