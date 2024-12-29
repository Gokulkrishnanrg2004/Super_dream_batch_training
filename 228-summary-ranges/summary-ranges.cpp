class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> result;
        if (nums.empty()) return result;
        int first = nums[0];
        for (int i = 0; i < nums.size(); i++) 
        {
            if (i == nums.size() - 1 || nums[i] + 1 != nums[i + 1]) 
            {
                int last = nums[i];
                if (first == last) 
                {
                    result.push_back(to_string(first));
                } 
                else 
                {
                    result.push_back(to_string(first) + "->" + to_string(last));
                }
                if (i != nums.size() - 1) 
                {
                    first = nums[i + 1];
                }
            }
        }
        
        return result;
    }
};
