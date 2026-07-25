// LC 64: Minimum Path Sum (Medium)
// Link: https://leetcode.com/problems/minimum-path-sum/
// Approach: Space-Optimized 1D Dynamic Programming. Track min sum from top (prev[j]) and left (curr[j-1]).
//           Recurrence: curr[j] = grid[i][j] + min(prev[j], curr[j-1]).
// Time: O(M * N) where M and N are grid dimensions.
// Space: O(N) auxiliary space.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, -1);
        
        // Base case: Pre-compute accumulated path sums for row 0
        prev[0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            prev[i] = prev[i - 1] + grid[0][i];
        }

        // Space-Optimized Tabulation for row 1 to m - 1
        for (int i = 1; i < m; i++) {
            vector<int> curr(n, -1);
            for (int j = 0; j < n; j++) {                
                if (j == 0) {
                    // Left column boundary: can only come from top (prev[0])
                    curr[j] = grid[i][j] + prev[j];
                }
                else {
                    // Min path sum coming from top vs left
                    curr[j] = min(grid[i][j] + prev[j], grid[i][j] + curr[j - 1]);
                }
            }
            prev = curr; // Move to next row
        }
        
        return prev[n - 1];
    }
};
