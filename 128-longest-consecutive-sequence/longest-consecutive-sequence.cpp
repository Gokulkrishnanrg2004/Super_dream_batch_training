class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.empty()) return 0;

        int count=1,flag=0,maxlen = 1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] - nums[i-1] == 1)
            {
                flag=1;
                count++;
            }
            else if(nums[i] != nums[i-1])
            {
                maxlen = max(maxlen,count);
                count=1;
                flag=0;
            }
        }    
        maxlen = max(maxlen,count);
        return maxlen;
    }
};