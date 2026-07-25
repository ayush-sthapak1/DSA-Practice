// LC 62: Unique Paths (Medium)
// Link: https://leetcode.com/problems/unique-paths/
// Approach: 1D Space-Optimized Dynamic Programming. Recurrence: dp[j] = dp[j] (top) + dp[j-1] (left).
//           Swap m and n to ensure minimal auxiliary space O(min(M, N)).
// Time: O(M * N) where M and N are grid dimensions.
// Space: O(min(M, N)) auxiliary space.

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Ensure n is the smaller dimension to minimize DP array space
        if (m < n) swap(m, n);
        
        // Base case: row 0 has 1 way to reach each cell
        vector<int> dp(n, 1);
        
        // Iterate through remaining rows
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1]; // dp[j] (top) + dp[j-1] (left)
            }
        }
        
        return dp[n - 1];
    }
};
