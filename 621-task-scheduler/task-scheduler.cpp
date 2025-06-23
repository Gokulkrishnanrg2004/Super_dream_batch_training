class Solution 
{
    public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        unordered_map<char,int>freq;
        for(int task : tasks)
        {
            freq[task]++;
        }
        priority_queue<int>pq;
        for(auto& val : freq)
        {
            pq.push(val.second);
        }
        int time = 0;
        while(!pq.empty())
        {
            int cycle = n+1;
            vector<int>temp;

            while(!pq.empty() && cycle > 0)
            {
                int val = pq.top();
                pq.pop();

                if(val > 1)
                {
                    temp.push_back(val-1);
                }
                time++;
                cycle--;
            }
            for(int t : temp)
            {
                pq.push(t);
            }
            if(!pq.empty())
            {
                time += cycle;
            }
        }
        return time;
    }
};