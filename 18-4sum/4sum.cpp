class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        set<vector<int>>set;
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                long long newt = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1,high = n-1;
                while(low<high)
                {
                    if(nums[low]+nums[high]<newt)
                    {
                        low++;
                    }
                    else if(nums[low]+nums[high]>newt)
                    {
                        high--;
                    }
                    else 
                    {
                        set.insert({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;
                    }
                }
            }
        }
        for(auto it:set)
        {
            ans.push_back(it);
        }
        return ans;
    }
};