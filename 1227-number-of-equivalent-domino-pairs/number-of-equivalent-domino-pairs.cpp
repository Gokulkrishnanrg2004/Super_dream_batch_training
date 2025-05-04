class Solution {
    public:
    // Custom hash function for pair<int, int>
    struct pair_hash 
    {
        size_t operator()(const pair<int, int>& p) const 
        {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        int n = dominoes.size();
        int count = 0;
        unordered_map<pair<int, int>, int, pair_hash>mp;
        for (auto& d : dominoes) 
        {
            // Sort the pair to ensure [1,2] and [2,1] are treated the same
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            pair<int, int> key = {a, b};

            count += mp[key];  
            mp[key]++;        
        }

        return count;
    }
};