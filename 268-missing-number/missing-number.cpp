class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++)
        // {
        //     if(i != nums[i])
        //     {
        //         return i;
        //     }
        // }    
        // return nums[n-1]+1;
        int n = nums.size();
        int total = n * (n + 1) / 2;
        for (int num : nums) 
        {
            total -= num;
        }
        return total;
    }
};