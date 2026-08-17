// LC 583: Delete Operation for Two Strings (Medium)
// Link: https://leetcode.com/problems/delete-operation-for-two-strings/
// Approach: Reduction to LCS. Total deletions = n + m - 2 * LCS(word1, word2).
//           Uses 1D space-optimized LCS tabulation.
// Time: O(N * M) where N and M are lengths of word1 and word2.
// Space: O(M) auxiliary space.

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Step 1: Compute LCS(word1, word2)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = 1 + prev[j - 1]; // Character match
                } else {
                    curr[j] = max(prev[j], curr[j - 1]); // Character mismatch
                }
            }
            prev = curr; // Move to next row
        }

        int maxLcsLen = prev[m];
        
        // Step 2: Total deletions = (n - LCS) + (m - LCS) = n + m - 2 * LCS
        return n + m - 2 * maxLcsLen;
    }
};
