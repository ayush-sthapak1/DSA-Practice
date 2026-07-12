// LC 994: Rotting Oranges (Medium)
// Link: https://leetcode.com/problems/rotting-oranges/
// Approach: Multi-source BFS starting from all rotten oranges.
//           Tracks fresh orange count to avoid visited array space.
// Time: O(m * n) where m and n are grid dimensions.
// Space: O(m * n) in the worst case for the queue.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Queue stores {{row, col}, time}
        queue<pair<pair<int,int>,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int freshCount = 0;

        // Initialize queue with all rotten oranges and count fresh ones
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) {
                    q.push({{i,j}, 0});
                } else if(grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // Direction vectors for 4-directional movement
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        while(!q.empty()){
            pair<pair<int,int>,int> curr = q.front();
            q.pop();
            int i = curr.first.first;
            int j = curr.first.second;
            int time = curr.second;

            ans = max(ans, time);

            // Traverse adjacent fresh oranges
            for(int d = 0; d < 4; d++) {
                int ni = i + dRow[d];
                int nj = j + dCol[d];

                if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                    grid[ni][nj] = 2; // Infect and mark as visited
                    freshCount--;
                    q.push({{ni, nj}, time + 1});
                }
            }
        }

        // If any fresh orange remains unreachable
        if(freshCount > 0) return -1;
        return ans;
    }
};
