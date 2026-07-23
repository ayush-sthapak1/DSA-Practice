// LC 827: Making A Large Island (Hard)
// Link: https://leetcode.com/problems/making-a-large-island/
// Approach: 1) DFS to tag each island component with a unique ID (>1) and record its size.
//           2) Check each '0' cell and sum unique neighbor island sizes to find max potential island.
// Time: O(N^2) where grid is N x N (each cell processed a constant number of times).
// Space: O(N^2) for DFS recursion stack and island size mapping.

class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c, int id) {
        int n = grid.size();
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 1) return 0;
        
        grid[r][c] = id; // Mark cell with unique island ID
        int size = 1;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            size += dfs(grid, r + dr[i], c + dc[i], id);
        }
        return size;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> islandSizes;
        int islandId = 2; // Unique IDs start from 2 to avoid confusion with 0 and 1
        int maxIsland = 0;

        // Step 1: Mark each island with a unique ID and calculate its size via DFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, islandId);
                    islandSizes[islandId] = size;
                    maxIsland = max(maxIsland, size);
                    islandId++;
                }
            }
        }

        // Step 2: Try changing each 0 to 1 and calculate the resulting combined island size
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighboringIslands;
                    
                    // Collect unique island IDs from all 4 directions
                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] > 1) {
                            neighboringIslands.insert(grid[nr][nc]);
                        }
                    }

                    int currentSize = 1; // 1 accounts for changing current '0' to '1'
                    for (int id : neighboringIslands) {
                        currentSize += islandSizes[id];
                    }
                    maxIsland = max(maxIsland, currentSize);
                }
            }
        }

        // Edge case: If maxIsland is still 0, grid has only 0s (result is 1).
        // If grid has only 1s, Step 1 already tracked the full grid size.
        return maxIsland == 0 ? 1 : maxIsland;
    }
};
