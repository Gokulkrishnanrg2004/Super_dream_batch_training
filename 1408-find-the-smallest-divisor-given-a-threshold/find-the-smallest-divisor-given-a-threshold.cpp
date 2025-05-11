class Solution {
    public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int n = nums.size();
        if(n > threshold) return -1;
        int low = 1,high = *max_element(nums.begin(),nums.end());
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int total = 0;
            for(auto num : nums)
            {
                total += ceil((double)num/mid);
            }
            if(total <= threshold)
            {
                high = mid - 1;
            }
            else 
            {
                low = mid + 1;
            }
        }
        return low;
    }
};