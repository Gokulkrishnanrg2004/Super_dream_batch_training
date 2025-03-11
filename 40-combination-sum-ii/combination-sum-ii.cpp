class Solution {
    public:
    void findComb(vector<int>&candidates,int target,int start,vector<int>&current,vector<vector<int>>&result)
    {
        if(target == 0)
        {
            result.push_back(current);
            return;
        }
        for(int j = start;j<candidates.size();j++)
        {
            if(j>start && candidates[j] == candidates[j-1])
                continue;

            if(candidates[j] > target)
                break;

            current.push_back(candidates[j]);
            findComb(candidates,target - candidates[j],j+1,current,result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>>result;
        vector<int>current;
        sort(candidates.begin(),candidates.end());
        findComb(candidates,target,0,current,result);
        return result;    
    }
};