// LC 1020: Number of Enclaves (Medium)
// Link: https://leetcode.com/problems/number-of-enclaves/
// Approach: Boundary DFS traversal. Mark boundary-connected 1s as 2 (visited/safe),
//           then count all remaining 1s (which are enclosed) and restore the grid.
// Time: O(m * n) where m and n are grid dimensions.
// Space: O(m * n) in the worst case for recursion stack.

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, const vector<int>& dr, const vector<int>& dc) {
        grid[r][c] = 2;
        for(int i = 0; i < 4; i++) {
            int row = r + dr[i]; 
            int col = c + dc[i];

            if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1) {
                dfs(grid, row, col, dr, dc);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        int count = 0;

        // Traverse boundaries and run DFS for any boundary 1
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1) dfs(grid, i, 0, dr, dc);
            if(grid[i][n - 1] == 1) dfs(grid, i, n - 1, dr, dc);
        }
        for(int j = 1; j < n - 1; j++) {
            if(grid[0][j] == 1) dfs(grid, 0, j, dr, dc);
            if(grid[m - 1][j] == 1) dfs(grid, m - 1, j, dr, dc);
        }

        // Final scan: count remaining 1s and restore the grid
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    count++;
                } else if(grid[i][j] == 2) {
                    grid[i][j] = 1; // Restore grid to its original state
                }
            }
        }

        return count;
    }
};
