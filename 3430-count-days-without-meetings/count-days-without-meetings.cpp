class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> merged;
        merged.push_back(meetings[0]);

        for(int i = 1; i < meetings.size(); i++) 
        {
            if(meetings[i][0] <= merged.back()[1]) 
            {
                merged.back()[1] = max(merged.back()[1], meetings[i][1]);
            } 
            else 
            {
                merged.push_back(meetings[i]);
            }
        }

        int count = 0;

        if(merged[0][0] > 1) 
        {
            count += merged[0][0] - 1;
        }

        for(int i = 1; i < merged.size(); i++) 
        {
            count += merged[i][0] - merged[i-1][1] - 1;
        }

        if(merged.back()[1] < days) 
        {
            count += days - merged.back()[1];
        }

        return count;
    }
};