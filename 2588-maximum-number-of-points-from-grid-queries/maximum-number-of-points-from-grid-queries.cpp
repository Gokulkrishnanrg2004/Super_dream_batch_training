class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) 
    {
         int m = grid.size(), n = grid[0].size();
    int k = queries.size();
    vector<int> result(k, 0);
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // Sorting queries along with their indices to map results correctly
    vector<pair<int, int>> sortedQueries;
    for (int i = 0; i < k; i++) {
        sortedQueries.emplace_back(queries[i], i);
    }
    sort(sortedQueries.begin(), sortedQueries.end());

    // Min-Heap (value, row, col)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({grid[0][0], {0, 0}});
    visited[0][0] = true;
    
    int count = 0; // Number of points collected
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Process queries in sorted order
    for (auto& [query, idx] : sortedQueries) {
        while (!pq.empty() && pq.top().first < query) {
            auto [value, pos] = pq.top();
            pq.pop();
            int r = pos.first, c = pos.second;
            count++;  // Earn point for visiting this cell

            // Explore 4 possible directions
            for (auto& d : directions) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    pq.push({grid[nr][nc], {nr, nc}});
                    visited[nr][nc] = true;
                }
            }
        }
        result[idx] = count;
    }

    return result;    
    }
};