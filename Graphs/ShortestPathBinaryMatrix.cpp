// LC 1091: Shortest Path in Binary Matrix (Medium)
// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Approach: BFS using a distance matrix to find the shortest clear path in 8 directions.
// Time: O(n^2) where n is grid dimension (each cell is processed at most once).
// Space: O(n^2) for the distArray and queue.

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Base edge cases
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n == 1) return 1;

        vector<vector<int>> distArray(n, vector<int>(n, INT_MAX));
        distArray[0][0] = 1;

        // Queue stores {distance, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        
        // Direction offsets for 8 cardinal and diagonal moves
        vector<int> dr = {-1, -1, -1, 0, +1, +1, +1, 0};
        vector<int> dc = {-1, 0, +1, +1, +1, 0, -1, -1};

        while(!q.empty()){
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            // Skip if we found a shorter path to this cell already
            if (dist > distArray[row][col]) continue;

            for(int i = 0; i < dr.size(); i++){
                int r = row + dr[i];
                int c = col + dc[i];
                int d = dist + 1;
                
                // Boundary check and clear path check
                if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0){
                    if(d < distArray[r][c]){
                        if(r == n - 1 && c == n - 1) return d; // Destination reached early
                        distArray[r][c] = d;
                        q.push({d, {r, c}});
                    }
                }
            }
        }
        
        return -1; // Path not found
    }
};
