class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_set<int>element;
        int left = 0;
        long long sum = 0,maxsum = 0;
        for(int right=0;right<n;right++)
        {
            while(element.count(nums[right]))
            {
                element.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            element.insert(nums[right]);
            sum += nums[right];

            if(right - left + 1 == k)
            {
                maxsum = max(maxsum,sum);
                element.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
        }    
        return maxsum;
    }
};