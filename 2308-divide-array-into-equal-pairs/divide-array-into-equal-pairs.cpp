class Solution {
    public:
    bool divideArray(vector<int>& nums) 
    {
        if(nums.size()%2 != 0)
        {
            return false;
        }
        int np = nums.size()/2;
        int count = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=2)
        {
            if(nums[i] == nums[i+1])
            {
                count++;
            }
        }    
        return count==np ? true : false;
    }
};