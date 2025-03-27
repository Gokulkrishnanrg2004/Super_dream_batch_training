class Solution {
public:
    int minimumIndex(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int dom = -1;
        int maxcount = INT_MIN;
        for(auto it : mp)
        {
            if(it.second > n/2)
            {
                dom = it.first;
                maxcount = it.second;
            }
        }
        int leftcount = 0,rightcount = maxcount;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==dom)
            {
                leftcount++;
                rightcount--;
            }
            if (leftcount * 2 > (i + 1) && rightcount * 2 > (n - i - 1)) 
            {
                return i;
            }
        }
        return -1;
    }
};