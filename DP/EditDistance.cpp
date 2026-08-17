// LC 72: Edit Distance (Hard)
// Link: https://leetcode.com/problems/edit-distance/
// Approach: Space-Optimized 1D Dynamic Programming.
//           If match: curr[j] = prev[j-1]
//           If mismatch: curr[j] = 1 + min({prev[j-1] (Replace), prev[j] (Delete), curr[j-1] (Insert)})
// Time: O(N * M) where N and M are the lengths of word1 and word2.
// Space: O(M) auxiliary space.

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Base case: Converting empty word1 to word2 of length j requires j insertions
        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++) {
            // Base case: Converting word1 of length i to empty word2 requires i deletions
            curr[0] = i;
            
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1]; // Character match: 0 operations
                } else {
                    // Mismatch: 1 + min(Replace, Delete, Insert)
                    curr[j] = min({1 + prev[j - 1],  // Replace
                                   1 + prev[j],      // Delete
                                   1 + curr[j - 1]}); // Insert
                }
            }
            prev = curr; // Move to next row
        }

        return prev[m];
    }
};
