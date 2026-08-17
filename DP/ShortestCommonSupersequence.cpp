// LC 1092: Shortest Common Supersequence (Hard)
// Link: https://leetcode.com/problems/shortest-common-supersequence/
// Approach: 2D LCS Table + Backtracking to reconstruct the string.
//           1) Build 2D DP table for LCS(str1, str2).
//           2) Backtrack from (n, m) to (0, 0) appending common LCS characters once and non-LCS characters from both strings.
//           3) Reverse the result string.
// Time: O(N * M) where N and M are lengths of str1 and str2.
// Space: O(N * M) for 2D DP table.

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        // Step 1: Build 2D DP table for LCS
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 2: Backtrack to build the Shortest Common Supersequence string
        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1]; // Character in LCS: include once
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    ans += str1[i - 1]; // Came from top: include str1 character
                    i--;
                } else {
                    ans += str2[j - 1]; // Came from left: include str2 character
                    j--;
                }
            }
        }
        
        // Append remaining characters from str1 if any
        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }

        // Append remaining characters from str2 if any
        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        // Step 3: Reverse as we built the answer backwards
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
