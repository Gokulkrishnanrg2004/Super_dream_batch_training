class Solution {
    public:
    int minOperations(vector<int>& nums, int k) 
    {
        unordered_set<int>greater;
        for(int num : nums)
        {
            if(num < k)
                return -1;

            if(num > k)
                greater.insert(num);
        }
        return greater.size();
    }
};