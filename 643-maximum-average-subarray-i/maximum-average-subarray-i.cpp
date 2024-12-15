class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int left = 0;
        int n = nums.size();
        double avg,maxavg = -DBL_MAX;;
        vector<int>arr;
        int sum=0;
        for(int right = 0;right<n;right++)
        {
            sum += nums[right];
            if(right - left + 1 == k)
            {
                avg = (double)sum/k;
                maxavg = max(maxavg,avg);
                sum -= nums[left];
                left++;
                arr.clear();
            }
        }    
        return maxavg;
    }
};