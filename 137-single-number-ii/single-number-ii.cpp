class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        //Using ones and twos approach based on the occurence
        int ones = 0;
        int twos = 0;
        for(int i=0;i<nums.size();i++)
        {
            ones = (ones ^ nums[i])&(~twos);
            twos = (twos ^ nums[i])&(~ones);
        }    
        return ones;
    }
};