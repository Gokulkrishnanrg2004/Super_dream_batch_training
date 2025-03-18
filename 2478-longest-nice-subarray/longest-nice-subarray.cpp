class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        int left = 0;
        int currOR = 0;
        int maxlen = 0;
        
        for(int right = 0;right < n;right++)
        {
            while((currOR & nums[right]) != 0)
            {
                currOR ^= nums[left];
                left++;
            }
            currOR |= nums[right];
            maxlen = max(maxlen, right - left + 1);
        }    
        return maxlen;
    }
};