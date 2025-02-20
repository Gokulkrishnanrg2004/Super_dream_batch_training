class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        do 
        {
            vector<int>arr;
            for(int num : nums)
            {
                arr.push_back(num);
            }
            result.push_back(arr);
        }while(next_permutation(nums.begin(),nums.end()));
        return result; 
    }
};