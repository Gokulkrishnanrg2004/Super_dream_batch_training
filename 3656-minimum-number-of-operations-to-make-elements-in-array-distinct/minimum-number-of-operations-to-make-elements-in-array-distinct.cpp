class Solution {
    public:
    bool isDistinct(vector<int>& nums)
    {
        int n = nums.size();
        set<int>s;
        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i]) != s.end())
            {
                return false;
            }
            s.insert(nums[i]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) 
    {
        int count = 0;
        while(!isDistinct(nums))
        {
            if (nums.size() >= 3) 
            {
                nums.erase(nums.begin(), nums.begin() + 3);
            } 
            else 
            {
                nums.clear(); 
            }
            count++;

            if (nums.empty()) break;
        }
        return count;
    }
};