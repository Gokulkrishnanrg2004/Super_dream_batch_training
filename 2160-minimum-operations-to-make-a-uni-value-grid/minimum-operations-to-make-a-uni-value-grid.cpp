class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        vector<int>arr;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr.push_back(grid[i][j]);   
            }
        }    
        int rem = arr[0]%x;

        for(int num : arr)
        {
            if(num % x != rem)
            {
                return -1;
            }
        }
        int operations = 0;

        sort(arr.begin(),arr.end());
        int median = arr[arr.size()/2];

        for(int num : arr)
        {
            operations += abs(num - median)/x;
        }
        return operations;
    }
};