// LC 778: Swim in Rising Water (Hard)
// Link: https://leetcode.com/problems/swim-in-rising-water/
// Approach: Dijkstra's Algorithm (Min-Priority Queue). Track path bottleneck max(time, grid[nr][nc]).
// Time: O(N^2 * log(N)) where N is the grid dimension.
// Space: O(N^2) for visited matrix and priority queue.

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // Min-Priority Queue storing {time_required, {r, c}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // Start from (0, 0) with initial time = grid[0][0]
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while(!pq.empty()){
            int time = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            // First time reaching (n-1, n-1) is guaranteed to be the minimum time
            if (r == n - 1 && c == n - 1) return time;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    int nextTime = max(time, grid[nr][nc]); // Bottleneck height on path
                    pq.push({nextTime, {nr, nc}});
                }
            }
        }

        return 0;
    }
};
