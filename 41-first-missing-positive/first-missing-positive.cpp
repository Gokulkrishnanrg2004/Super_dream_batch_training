class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] > 0) 
            {
                ans.push_back(nums[i]);
            }
        }
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        if (ans.empty() || ans[0] != 1) 
        {
            return 1; 
        }
        
        for (int i = 1; i < ans.size(); i++) 
        {
            if (ans[i] != ans[i-1] + 1) 
            {
                return ans[i-1] + 1;
            }
        }
        return ans.back() + 1;
    }
};
