class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
         priority_queue<int> pq; 
    int fuel = startFuel, stops = 0, idx = 0;
    while (fuel < target) {
      
        while (idx < stations.size() && stations[idx][0] <= fuel) {
            pq.push(stations[idx][1]);
            idx++;
        }
        if (pq.empty()) return -1;
        fuel += pq.top();
        pq.pop();
        stops++;
    }
    return stops;
    }
};