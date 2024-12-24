class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int ele = 0,count = 0;
        for(int num : nums)
        {
            if(count == 0)
            {
                ele = num;
            }
            count += (num == ele) ? 1 : -1;
        }
        return ele;
    }
};