class Solution {
public:
    int findNumbers(vector<int>& nums) 
    {
        vector<string>arr;
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            arr.push_back(to_string(nums[i]));
        }    
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i].length() % 2 == 0)
            {
                count++;
            }
        }
        return count;
    }
};