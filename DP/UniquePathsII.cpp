// LC 63: Unique Paths II (Medium)
// Link: https://leetcode.com/problems/unique-paths-ii/
// Approach: Space-Optimized 1D Dynamic Programming. Track paths from top (prev[j]) and left (curr[j-1]).
//           If obstacleGrid[i][j] == 1, curr[j] = 0 (no paths pass through an obstacle).
// Time: O(M * N) where M and N are grid dimensions.
// Space: O(N) auxiliary space.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);

            for (int j = 0; j < n; j++) {
                // Obstacle cell: 0 paths can pass through
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                }
                // Base case: Starting point
                else if (i == 0 && j == 0) {
                    curr[j] = 1;
                }
                // Transitions from top and left
                else {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j - 1] : 0;
                    curr[j] = up + left;
                }
            }
            prev = curr; // Move to next row
        }

        return prev[n - 1];
    }
};
