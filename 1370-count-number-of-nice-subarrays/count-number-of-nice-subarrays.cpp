class Solution {
    public:
    int getnice(vector<int>&nums,int k)
    {
    if(k<0)
    {
        return 0;
    }
    int left = 0;
    int n = nums.size();
    int countodd = 0;
    int maxarr = 0;
    
    
    for(int right = 0;right<n;right++)
    {
        if(nums[right]%2 != 0) countodd++;

        while(countodd > k)
        {
            if(nums[left]%2 != 0) countodd--;
            left++;
        }
        maxarr += right - left + 1; 
    }
    return maxarr;
    }
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int sum1 = getnice(nums,k);
        int sum2 = getnice(nums,k-1);
        return sum1 - sum2;
    }
};