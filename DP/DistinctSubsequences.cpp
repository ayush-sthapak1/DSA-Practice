// LC 115: Distinct Subsequences (Hard)
// Link: https://leetcode.com/problems/distinct-subsequences/
// Approach: Single 1D Vector Space-Optimized Dynamic Programming (Backward Loop).
//           Recurrence: if s[i-1] == t[j-1] -> dp[j] = dp[j-1] (pick) + dp[j] (not pick).
// Time: O(N * M) where N and M are the lengths of strings s and t.
// Space: O(M) auxiliary space.

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        // 1D DP array of size m + 1 initialized to 0.
        // double type prevents 32-bit integer overflow on intermediate DP additions.
        vector<double> dp(m + 1, 0);

        // Base case: 1 way to form an empty string t
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            // Loop j backwards to ensure dp[j-1] is from the previous character state (i-1)
            for (int j = m; j > 0; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j - 1] + dp[j]; // pick + not-pick
                }
            }
        }

        return (int)dp[m];
    }
};
