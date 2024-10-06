class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,int>Map;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            Map[nums[i]]++;
            if(Map[nums[i]]>1)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};