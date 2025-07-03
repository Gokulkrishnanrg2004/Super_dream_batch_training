class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int median = nums[n/2];
        int minMoves = 0;
        for(int i=0;i<n;i++)
        {
            minMoves += abs(median - nums[i]);
        }    
        return minMoves;
    }
};