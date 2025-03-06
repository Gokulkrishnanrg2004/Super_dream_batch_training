class Solution {
    public:
    int finddup(vector<int>&arr)
    {
        int result = 0;
        unordered_set<int>seen;
        for(int num : arr)
        {
            if(seen.find(num) != seen.end())
            {
                return num;
            }
            seen.insert(num);
        }
        return result;
    }
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<int>result;
        for(auto r:grid)
        {
            for(auto c:r)
            {
                result.push_back(c);
            }
        }    
        sort(result.begin(),result.end());
        int dup1 = finddup(result);
        result.erase(unique(result.begin(),result.end()),result.end());
        int dup2;
        for(int i=0;i<n*n;i++)
        {
            if (i >= result.size() || result[i] != i + 1) {
                dup2 = i + 1;
                break; 
            }
        }
        return {dup1,dup2};

    }
};