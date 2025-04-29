class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int left = 0;
        long long maxi = *max_element(nums.begin(),nums.end()), maxOcc = 0, res = 0;
        for(int right = 0;right < nums.size();right++)
        {
            if(nums[right] == maxi)
            {
                maxOcc++;
            }
            while(maxOcc >= k)
            {
                if(nums[left] == maxi)
                {
                    maxOcc--;
                }
                left++;
            }
            res += left;
        }    
        return res;
    }
};