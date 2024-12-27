class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int minindex = INT_MAX;  // To track the minimum subarray length
        int n = nums.size();
        int sum = 0, start = 0;

        for (int end = 0; end < n; end++) 
        {
            sum += nums[end];  // Add the current element to the running sum

            // Shrink the window while the sum is greater than or equal to the target
            while (sum >= target) 
            {
                minindex = min(minindex, end - start + 1);  // Update the minimum length
                sum -= nums[start];  // Remove the leftmost element from the sum
                start++;  // Move the start of the window to the right
            }
        }

        return (minindex == INT_MAX) ? 0 : minindex;  // If no subarray found, return 0
    }
};
