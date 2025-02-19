class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        queue<int>q;
        int time = 0;
        for(int i=0;i<tickets.size();i++)
        {
            q.push(i);
        }   
        while(!q.empty())
        {
            int index = q.front();
            q.pop();

            tickets[index]--;
            time++;

            if(index == k && tickets[index]==0)
            {
                return time;
            }
            if(tickets[index] > 0)
            {
                q.push(index);
            }
        }
        return time;
    }
};