class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        
        int count = 1, maxlen = 1; // Start with 1 as the sequence count
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue; // Skip duplicates
            }
            if (nums[i] - nums[i - 1] == 1) {
                // If consecutive, increase count
                count++;
            } else {
                // Reset count when the sequence breaks
                maxlen = max(maxlen, count);
                count = 1; // Reset count for the next sequence
            }
        }
        
        // Update maxlen in case the longest sequence ends at the last element
        maxlen = max(maxlen, count);
        
        return maxlen; // Return the longest sequence length
    }
};
