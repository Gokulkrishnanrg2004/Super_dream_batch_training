class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>Map;
        Map[0] = -1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem = sum%k;
            if(Map.find(rem)!=Map.end())
            {
                if(i - Map[rem] >= 2)
                {
                    return true;
                }
            }
            else 
            {
                Map[rem] = i;
            }
        }
        return false;
    }
};
