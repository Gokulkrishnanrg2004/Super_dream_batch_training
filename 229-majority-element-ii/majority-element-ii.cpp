class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>res;
        map<int,int>mp;
        int mini = (n/3)+1;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==mini)
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};