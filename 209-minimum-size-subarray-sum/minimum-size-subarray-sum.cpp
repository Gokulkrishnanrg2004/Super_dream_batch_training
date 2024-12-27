class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int minindex = INT_MAX;
        int n = nums.size();
        int sum = 0, start = 0;

        for (int end = 0; end < n; end++) 
        {
            sum += nums[end]; 
            while (sum >= target) 
            {
                minindex = min(minindex, end - start + 1);  
                sum -= nums[start];  
                start++; 
            }
        }
        return (minindex == INT_MAX) ? 0 : minindex;  
    }
};
