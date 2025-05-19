class Solution {
public:
    string triangleType(vector<int>& nums) 
    {
        string result = "";
        if(nums[0] == nums[1] && nums[1] == nums[2] && nums[2] == nums[0])
        {
            if(nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] && nums[0] + nums[2] > nums[1])
            {
                result = "equilateral";
            }
            else 
            {
                result = "none";
            }
        }    
        else if(nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0])
        {
            if(nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] && nums[0] + nums[2] > nums[1])
            {
                result = "isosceles";
            }
            else 
            {
                result = "none";
            }
        }
        else if(nums[0] != nums[1] && nums[1] != nums[2] && nums[2] != nums[0])
        {
            if(nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] && nums[0] + nums[2] > nums[1])
            {
                result = "scalene";
            }
            else 
            {
                result = "none";
            }
        }

        return result;
    }
};