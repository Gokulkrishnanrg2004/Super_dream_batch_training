class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        long long sum = 0;
        int n = nums.size();
        for(int start = 0;start<n;start++)
        {
            int minele = nums[start],maxele = nums[start];
            for(int end = start;end<n;end++)
            {
                minele = min(minele,nums[end]);
                maxele = max(maxele,nums[end]);
                sum += maxele - minele;
            }
        }    
        return sum;
    }
};