class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int,int>Map;
        Map[0] = 1;
        int sum=0,count=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem= sum%k;
            if(rem < 0) 
                rem += k;
            if(Map.find(rem)!=Map.end())
            {
                count+=Map[rem];
            }
            Map[rem]++;
        }
        return count;
    }
};