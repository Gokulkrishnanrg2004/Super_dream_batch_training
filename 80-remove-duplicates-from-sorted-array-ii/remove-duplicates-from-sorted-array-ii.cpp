class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int index = 0,count=0,value = nums[0];
        for(auto val:nums)
        {
            if(value==val)
                count++;
            else 
            {
                count = 1;
                value = val;
            }
            if(count<=2)
                nums[index++] = val;
        }
        return index;
    }
};