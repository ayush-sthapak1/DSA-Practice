// LC 1143: Longest Common Subsequence (Medium)
// Link: https://leetcode.com/problems/longest-common-subsequence/
// Approach: Space-Optimized 1D Dynamic Programming.
//           Shift indices by +1 to represent empty string base cases (0s).
//           Recurrence: if text1[i-1] == text2[j-1] -> curr[j] = 1 + prev[j-1]
//                       else -> curr[j] = max(prev[j], curr[j-1])
// Time: O(N * M) where N and M are the lengths of text1 and text2.
// Space: O(M) auxiliary space.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // prev and curr vectors store LCS results for current and previous row
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1]; // Character match: extend LCS from diagonal
                } else {
                    curr[j] = max(prev[j], curr[j - 1]); // Mismatch: take max of top or left
                }
            }
            prev = curr; // Move to next row
        }

        return prev[m];
    }
};
