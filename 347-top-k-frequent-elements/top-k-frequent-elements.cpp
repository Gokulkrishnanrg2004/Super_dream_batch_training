class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto it : mp)
        {
            q.push({it.second, it.first}); // the priority queue is pushed based on frequency which is it.second
        }
        vector<int>res;
        while(k--)
        {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};