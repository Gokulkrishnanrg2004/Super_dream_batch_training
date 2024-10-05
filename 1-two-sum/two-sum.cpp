class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //Bruteforce approach
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         if(nums[i]+nums[j]==target)
        //         {
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++)
        {
            int complement = target - nums[i];
            if(map.find(complement)!=map.end())
            {
                return {i,map[complement]};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};