class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);

        for(auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int countComplete = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                queue<int>q;
                q.push(i);
                visited[i] = true;

                vector<int>component;
                int edgeCount = 0;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);
                    edgeCount += adj[node].size();

                    for(int neighbour : adj[node])
                    {
                        if(!visited[neighbour])
                        {
                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }
                }
                int sz = component.size();
                int total = edgeCount/2;
                if(total == sz*(sz-1)/2)
                {
                    countComplete++;
                }
            }
        }
        return countComplete;
    }
};