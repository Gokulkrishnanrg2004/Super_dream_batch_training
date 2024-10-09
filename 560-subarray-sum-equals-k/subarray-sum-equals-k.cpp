class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>Map;
        Map[0] = 1;
        int sum=0,count=0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem = sum - k;
            if(Map.find(rem)!=Map.end())
            {
                count += Map[rem];
            }
            Map[sum]++;
        }
        return count;
    }
};